#include "main_window.h"
#include <commands.h>
#include <memory>
#include <boost/lexical_cast.hpp>
#include <boost/cast.hpp>
#include <boost\filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <QFileDialog>
#include <QComboBox>
#include <QSplitter>
#include <QDebug>
#include <QPixmap>
#include <QSharedPointer>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	m_dir_model(nullptr),
	m_file_model(nullptr),
	m_progress_bar(nullptr),
	m_error_message(nullptr)
{
	ui.setupUi(this);
	
	m_dir_model = new QFileSystemModel();
	m_file_model = new QStandardItemModel();
	m_progress_bar = new QProgressBar();
	m_com = std::make_unique<store::Commands>();
	m_error_message = new QMessageBox();

	//qt-object settings
	m_error_message->setIcon(QMessageBox::Icon::Critical);
	m_error_message->addButton(QMessageBox::StandardButton::Ok);
	m_progress_bar->setValue(0);
	m_progress_bar->setVisible(false);
	//ui settings
	ui.listViewFolderData->setModel(m_file_model);
	ui.pushButtonFilter->setDisabled(true);
	ui.pushButtonExtract->setDisabled(true);
	ui.textEditFileContent->setReadOnly(true);
	ui.statusBar->addWidget(m_progress_bar);
	ui.splitter->setCollapsible(0, false);
	ui.splitter->setCollapsible(1, false);
	ui.splitter->setCollapsible(2,false);
	ui.comboBoxFieldName->addItems(QStringList({ "First name", "Last name", "Gender","Age", "Height", "Confidence", "Position" }));
	ui.comboBoxFieldName->AdjustToContents();
	m_dir_model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
	ui.listViewFolderData->setResizeMode((QListView::ResizeMode::Adjust));
	//connections
	connect(this, &MainWindow::addFileItemSignal, this, &MainWindow::addFileItems, Qt::UniqueConnection);
	connect(this, &MainWindow::finishedLoadingFiles, this, &MainWindow::compeleteLoading, Qt::UniqueConnection);
	connect(this, &MainWindow::progressChanged, this, &MainWindow::setProgressbar, Qt::UniqueConnection);
	connect(this, &MainWindow::disableCheckBox, this, &MainWindow::on_pushButtonFilter_stateChanged, Qt::UniqueConnection);
	connect(this, &MainWindow::hideRowSignal, this, &MainWindow::hideRowSlot, Qt::UniqueConnection);
	connect(this, &MainWindow::windowTitleSignal, this, &MainWindow::windowTitleSlot, Qt::UniqueConnection);
	connect(this, &MainWindow::fileContentSignal, this, &MainWindow::fileContentSlot, Qt::UniqueConnection);
	connect(this, &MainWindow::setLabelFileCountSignal, this, &MainWindow::setLabelFileCountSlot, Qt::UniqueConnection);
	connect(this, &MainWindow::showErrorMessageSignal, this, &MainWindow::showErrorMessageSlot, Qt::UniqueConnection);
	//
}
//SLOTS
//
void MainWindow::hideRowSlot(int _index, bool _boolean)
{
	ui.listViewFolderData->setRowHidden(_index, _boolean);
}

void MainWindow::setProgressbar(int _value)
{
	m_progress_bar->setValue(_value);
}

void MainWindow::setLabelFileCountSlot(QString _text)
{
	ui.labelFileCount->setText(_text);
}

void MainWindow::fileContentSlot(QString _file_content)
{
	ui.textEditFileContent->setText(_file_content);
}

void MainWindow::windowTitleSlot(QString _title)
{
	this->setWindowTitle(_title);
}

void MainWindow::showErrorMessageSlot()
{
	m_error_message->critical(this, "Error", QString::fromStdString(m_com->GetError(m_err)), QMessageBox::StandardButton::Close);
}

void MainWindow::compeleteLoading()
{
	boost::mutex::scoped_lock lock_method(m_mutex_data);
	/*
	if (m_stop_load)
		m_stop_load = false;
	if (m_stop_filter)
		m_stop_filter = false;
	*/
	ui.pushButtonImport->setText("Import");
	ui.pushButtonImport->setDisabled(false);
	ui.pushButtonFilter->setDisabled(false);
	ui.pushButtonExtract->setDisabled(false);
	ui.checkBoxTxt->setDisabled(false);
	ui.labelFileCount->setText(QString::fromStdString(std::to_string(m_file_count.at(0)))+" "+"files.");
	m_progress_bar->setVisible(false);
	ui.statusBar->clearMessage();
	ui.treeViewImportedData->setDisabled(false);
	if (!ui.pushButtonExtract->isEnabled())
		ui.pushButtonExtract->setDisabled(false);
}

void MainWindow::addFileItems(QStringList _items)
{
	
	auto file_count = m_file_count;
	int counter = 0;
	m_file_model->clear(); 
	auto name_item = new QStandardItem(QString::fromStdString("Name"));
	m_file_model->setHorizontalHeaderItem(0, name_item);

	m_file_model->setRowCount(_items.size());
	qDebug() << "here";
	for (int i = 0; i < _items.size(); i++)
	{
		auto item = new QStandardItem(_items.at(i));
		item->setEditable(false);
		m_file_model->setItem(i, 0, item);
	}
	
}
//
//QT FUNCTIONS
void MainWindow::on_pushButtonImport_clicked()
{
	if (ui.pushButtonImport->text() == "Cancel")
	{
		ui.pushButtonImport->setDisabled(true);
		ui.statusBar->showMessage("trying to stop loading data...");
		if (m_thread_load_folder.joinable())
		{
			m_stop_load = true;
			m_thread_load_folder.join();
		}
		if (m_thread_filter.joinable())
		{
			m_stop_filter = true;
			m_thread_filter.join();
		}
		m_file_model->clear();
		emit finishedLoadingFiles();
		return;
	}

	QString parent_dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		"/home", QFileDialog::ShowDirsOnly);
	if (!parent_dir.isEmpty())
	{
		m_file_model->clear();
		QDir directory(parent_dir);
		m_directory = directory.absolutePath().toStdString();
		m_dir_model->setRootPath(directory.absolutePath());
		ui.treeViewImportedData->setModel(m_dir_model);
		ui.treeViewImportedData->setRootIndex(m_dir_model->index(directory.absolutePath()));
		ui.pushButtonExtract->setDisabled(false);

	}
}

void MainWindow::on_comboBoxFieldName_currentTextChanged(const QString& _text)
{
	ui.comboBoxComp->clear();
	if (_text == QString::fromStdString("Age") | _text == QString::fromStdString("Height") | _text == QString::fromStdString("Confidence"))
		ui.comboBoxComp->addItems(QStringList({ "=","<",">" }));
	else
		ui.comboBoxComp->addItem(QString::fromStdString( "=" ));
	ui.comboBoxComp->AdjustToContents();
}

void MainWindow::on_checkBoxTxt_stateChanged()
{
	int txt_files = m_file_count.at(1);
	int files = m_file_count.at(0);
	if (ui.checkBoxTxt->isChecked())
	{
		int txt_counter = 0;
		emit setLabelFileCountSignal(QString::fromStdString(std::to_string(txt_files)) + " " + "files.");
		qDebug() << m_file_count.at(0);
		for (int i = 0; i < m_file_count.at(0); i++)
		{
			std::string file = m_file_model->item(i, 0)->text().toStdString();
			if (file.substr(file.find(".")) != ".txt")
			{
				emit hideRowSignal(i, true);
				txt_counter++;
			}
			if (txt_counter == txt_files)
				return;
		}
	}
	else
	{
		int unhidden = 0;
		emit setLabelFileCountSignal(QString::fromStdString(std::to_string(files)) + " " + "files.");
		for(int i = 0; i < m_file_count.at(0); i++)
			if (ui.listViewFolderData->isRowHidden(i))
			{
				emit hideRowSignal(i, false);
				unhidden++;
				if (unhidden == txt_files)
					return;
			}
		
	}
	
}

void MainWindow::on_treeViewImportedData_clicked(const QModelIndex& _index)
{
	ui.checkBoxTxt->setCheckState(Qt::CheckState::Unchecked);
	ui.treeViewImportedData->setDisabled(true);
	ui.pushButtonFilter->setText("Filter");
	ui.pushButtonFilter->setDisabled(true);
	ui.pushButtonExtract->setDisabled(true);
	ui.checkBoxTxt->setDisabled(true);
	m_file_model->clear();
	m_com->clear();
	QString dir = m_dir_model->fileInfo(_index).absoluteFilePath();
	QDirIterator it(dir, QDir::Files, QDirIterator::Subdirectories);
	ui.statusBar->showMessage("Loading files...");
	ui.pushButtonImport->setText("Cancel");
	m_progress_bar->setVisible(true);

	m_file_count = m_com->countFiles(boost::filesystem::path(dir.toStdString()));
	ui.labelFileCount->setText(QString::fromStdString(std::to_string(m_file_count.at(0))) + " " + "files.");
	m_thread_load_folder = boost::thread(&MainWindow::loadFileList, this, dir.toStdString());

}

void MainWindow::on_pushButtonFilter_stateChanged(bool _boolean)
{
	ui.checkBoxTxt->setDisabled(_boolean);
}

void MainWindow::on_pushButtonFilter_clicked()
{
	if (ui.lineEdit->text().isEmpty())
		return;
	if (ui.pushButtonFilter->text() == "Unfilter")
	{	
		ui.checkBoxTxt->setCheckState(Qt::CheckState::Unchecked);
		ui.pushButtonFilter->setText("Filter");
		ui.labelFileCount->setText(QString::fromStdString(std::to_string(m_file_count.at(0))) + " " + "files.");
		for (int i = 0; i < m_file_count.at(0); i++)
			if (ui.listViewFolderData->isRowHidden(i))
				emit hideRowSignal(i, false);
		ui.checkBoxTxt->setDisabled(false);
		
		return;
	}
	if (ui.pushButtonFilter->text() == "Cancel")
	{
		ui.checkBoxTxt->setCheckState(Qt::CheckState::Unchecked);
		for (int i = 0; i < m_file_count.at(0); i++)
			if (ui.listViewFolderData->isRowHidden(i))
				emit hideRowSignal(i, false);
		ui.pushButtonFilter->setText("Filter");
		ui.checkBoxTxt->setDisabled(false);
		ui.labelFileCount->setText(QString::fromStdString(std::to_string(m_file_count.at(0))) + " " + "files.");
		return;
	}
	ui.pushButtonFilter->setText("Cancel");

	m_thread_filter = boost::thread(&MainWindow::filterItems, this);
}

void MainWindow::on_listViewFolderData_clicked(const QModelIndex& _index)
{
	int item_index = _index.row();
	auto it = m_index_to_person.find(item_index);

	if (it == m_index_to_person.end())
		return;
	else
	{
		m_thread_file_content = boost::thread(&MainWindow::showItemContent, this, item_index);
	}
}

void MainWindow::on_pushButtonExtract_clicked()
{
	ui.pushButtonExtract->setDisabled(true);
	ui.checkBoxTxt->setCheckState(Qt::CheckState::Unchecked);
	ui.treeViewImportedData->setDisabled(true);
	ui.pushButtonFilter->setText("Filter");
	ui.pushButtonFilter->setDisabled(true);
	ui.pushButtonExtract->setDisabled(true);
	ui.checkBoxTxt->setDisabled(true);
	m_file_model->clear();
	m_com->clear();

	ui.statusBar->showMessage("Loading files...");
	ui.pushButtonImport->setText("Cancel");
	m_progress_bar->setVisible(true);

	m_file_count = m_com->countFiles(boost::filesystem::path(m_directory));
	ui.labelFileCount->setText(QString::fromStdString(std::to_string(m_file_count.at(0))) + " " + "files.");
	m_thread_load_folder = boost::thread(&MainWindow::loadFileList, this, m_directory);
}
//
//THREAD FUNCTIONS
//
void MainWindow::loadFileList(const std::string _relative_path_file)
{
	emit progressChanged(0);
	m_err = store::ErrorEnum::No_Error;
	auto p = boost::filesystem::path{_relative_path_file };
	m_p = p;

	std::fstream file_stream_read;
	std::string line;
	std::vector<std::shared_ptr<store::Person>> data;
	try
	{
		if (!exists(p))
		{
			m_err = store::ErrorEnum::Path_Does_Not_Exist;
			emit showErrorMessageSignal();
		}
		else
		{
			if (!is_directory(p))
			{
				m_err = store::ErrorEnum::Not_A_Regular_File_Or_Directory;
				emit showErrorMessageSignal();
			}
			else
			{
				QStringList item_list;
				int file_count = m_file_count.at(0);
				float portion = 100.0 / file_count;
				int counter = 0;
				int item_index = -1;
				for (boost::filesystem::directory_entry& x : boost::filesystem::recursive_directory_iterator(p))
				{
					if (m_stop_load)
					{
						emit finishedLoadingFiles();
						return;
					}
					if (x.path().extension() == ".txt" | x.path().extension() == ".jpg")
					{
						item_index++;
						item_list.append(QString::fromStdString(x.path().filename().string()));
					}
					if (x.path().extension() == ".txt")
					{
						
						file_stream_read.open(x.path().string());
						if (!file_stream_read.is_open())
						{
							m_err = store::ErrorEnum::File_Could_Not_Opened;
							emit showErrorMessageSignal();
						}
						else
						{
							std::vector<std::string>* vect = new std::vector<std::string>;
							while (getline(file_stream_read, line))
							{
								vect->push_back(line.substr(3));
							}
							file_stream_read.close();
							std::shared_ptr<store::Person> pers = std::make_shared<store::Person>();
							pers->SetPerson(vect->at(2), vect->at(3), stoi(vect->at(4)), stoi(vect->at(5)), vect->at(6), boost::lexical_cast<float>(vect->at(7)), x.path().filename().string(), item_index);
							pers->SetDateAndAge(vect->at(0), vect->at(1));
							data.push_back(pers);
							m_index_to_person[item_index] = pers;
							delete vect;
							vect = nullptr;
						}
					}
					counter++;
					emit progressChanged(int(counter * portion));
				}
				m_com->SetData(data);
				emit addFileItemSignal(item_list);
				emit finishedLoadingFiles();
				
			}
		}
	}

	catch (const boost::filesystem::filesystem_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}
void MainWindow::showItemContent(const int& _item_index)
{
	std::shared_ptr<store::Person> person = m_index_to_person[_item_index];
	std::string path = person->GetPath();
	std::string file_content =  person->GetAllData();
	emit fileContentSignal(QString::fromStdString(file_content));
	emit windowTitleSignal(QString::fromStdString(person->GetPath()));
}

bool compP(std::shared_ptr<int> _a, std::shared_ptr<int> _b)
{
	return *_a < *_b;
}

void MainWindow::filterItems()
{
	m_com->ClearSelected();

	bool is_number = true;
	store::FieldNameEnum fieldname = m_com->fieldname[ui.comboBoxFieldName->currentText().toStdString()];
	store::CompEnum comp = m_com->comp[ui.comboBoxComp->currentText().toStdString()];
	std::string line_edit_input = ui.lineEdit->text().toStdString();

	for (char const& c : line_edit_input)
		if ((std::isdigit(c) == 0) & (c != char(".")))
			is_number = false;
	// check if number or string then filter
	if (is_number)
	{
		if (fieldname == store::FieldNameEnum::Confidence)
		{
			float value = boost::lexical_cast<float>(line_edit_input);
			m_com->Select(fieldname, comp, value, m_err);
		}
		else
		{
			int value = boost::lexical_cast<int>(line_edit_input);
			m_com->Select(fieldname, comp, value, m_err); // outside if-else statement value becomes unidentified in m_com->select

		}
	}
	else
	{
		std::string value = ui.lineEdit->text().toStdString();
		m_com->Select(fieldname, comp, value, m_err);
	}
	//show filtered items if no error
	if (m_err != store::ErrorEnum::No_Error)
		emit showErrorMessageSignal();
	else
	{
		emit disableCheckBox(true);
		ui.checkBoxTxt->setCheckState(Qt::CheckState::Checked);
		std::vector<std::shared_ptr<store::Person>> selected = m_com->GetSelected();
		int selected_size = selected.size();
		ui.pushButtonFilter->setText("Unfilter");
		std::vector<std::shared_ptr<int>> index_to_keep;
		for (const auto& person : selected)
		{
			index_to_keep.push_back(std::make_shared<int>(person->GetItemIndex()));
		}
		std::sort(index_to_keep.begin(), index_to_keep.end(), compP);
		int j = 0;
		for (int i = 0; i < m_file_count.at(0); i++)
		{
			if (m_stop_filter)
				return;
			if (j < selected_size)
			{
				if (*index_to_keep.at(j) == i)
				{	
					emit hideRowSignal(i, false);
					j++;
				}
				else
					emit hideRowSignal(i, true);
			}
			else
				emit hideRowSignal(i, true);
		}
		emit setLabelFileCountSignal(QString::fromStdString(std::to_string(selected.size())) + " " + "files.");
		return;
	}
}
//

MainWindow::~MainWindow()
{
	if (m_thread_load_folder.joinable())
	{
		m_stop_load = true;
		m_thread_load_folder.join();
	}
	if (m_thread_filter.joinable())
	{
		m_stop_filter = true;
		m_thread_filter.join();
	}
	if (m_thread_file_content.joinable())
	{
		m_stop_content = true;
		m_thread_file_content.join();
	}
	delete m_dir_model;
	m_dir_model = nullptr;

	delete m_file_model;
	m_file_model = nullptr;

	delete m_progress_bar;
	m_progress_bar = nullptr;

	delete m_error_message;
	m_error_message = nullptr;
}