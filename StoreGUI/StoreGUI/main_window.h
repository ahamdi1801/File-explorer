#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include <commands.h>
#include <QStandardItemModel>
#include <qsharedpointer.h>
#include<qfilesystemmodel.h>
#include <QProgressBar>
#include <QMessageBox>
#include <qgraphicsscene.h>
#include <boost/thread/thread.hpp>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow();

signals:
	void progressChanged(int);
	void finishedLoadingFiles();
	void disableCheckBox(bool _boolean); //with connection because does not work with threads
	void hideRowSignal(int _index, bool _boolean);
	void windowTitleSignal(QString _title);
	void fileContentSignal(QString _file_content);
	void setLabelFileCountSignal(QString _text);
	void addFileItemSignal(QStringList _items);
	void showErrorMessageSignal();

private slots:
	//buttons
	void on_pushButtonImport_clicked();
	void on_pushButtonFilter_clicked();
	void on_pushButtonExtract_clicked();
	void on_checkBoxTxt_stateChanged();
	void on_comboBoxFieldName_currentTextChanged(const QString& _text);
	//view widgets
	void on_treeViewImportedData_clicked(const QModelIndex& _index);
	void on_listViewFolderData_clicked(const QModelIndex& _index);
	//
	void loadFileList(const std::string _relative_path_file);
	void setProgressbar(int);
	void compeleteLoading();
	void addFileItems(QStringList _items);
	void filterItems();
	void hideRowSlot(int _index, bool _boolean);
	void showItemContent(const int& _item_index);
	void windowTitleSlot(QString _title);
	void fileContentSlot(QString _file_content);
	void setLabelFileCountSlot(QString _text);
	void showErrorMessageSlot();

	void on_pushButtonFilter_stateChanged(bool _boolean);
private:
	Ui::MainWindow ui;
	QMessageBox* m_error_message;
	QFileSystemModel* m_dir_model;
	QStandardItemModel* m_file_model;
	QProgressBar* m_progress_bar;
	std::shared_ptr<store::Commands> m_com;
	store::ErrorEnum m_err;

	boost::filesystem::path m_p;
	std::vector<int> m_file_count;
	std::string m_directory;
	std::map<int, std::shared_ptr<store::Person>> m_index_to_person;

	boost::thread m_thread_load_folder;
	boost::thread m_thread_filter;
	boost::thread m_thread_file_content;
	boost::mutex m_mutex_data;
	


	std::atomic<bool> m_stop_load;
	std::atomic<bool> m_stop_filter;
	std::atomic<bool> m_stop_content;

};


#endif
