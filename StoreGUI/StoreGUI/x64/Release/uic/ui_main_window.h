/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxTxt;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutLeft;
    QHBoxLayout *horizontalLayoutLeft;
    QPushButton *pushButtonImport;
    QSpacerItem *horizontalSpacer;
    QTreeView *treeViewImportedData;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayoutCenter;
    QHBoxLayout *horizontalLayoutCenter;
    QComboBox *comboBoxFieldName;
    QComboBox *comboBoxComp;
    QLineEdit *lineEdit;
    QLabel *labelFileCount;
    QPushButton *pushButtonFilter;
    QListView *listViewFolderData;
    QWidget *layoutWidget2;
    QVBoxLayout *rightLayout;
    QPushButton *pushButtonExtract;
    QTextEdit *textEditFileContent;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(970, 354);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxTxt = new QCheckBox(centralwidget);
        checkBoxTxt->setObjectName(QString::fromUtf8("checkBoxTxt"));
        checkBoxTxt->setEnabled(true);
        checkBoxTxt->setChecked(false);

        gridLayout->addWidget(checkBoxTxt, 1, 0, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayoutLeft = new QVBoxLayout(layoutWidget);
        verticalLayoutLeft->setObjectName(QString::fromUtf8("verticalLayoutLeft"));
        verticalLayoutLeft->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayoutLeft->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutLeft = new QHBoxLayout();
        horizontalLayoutLeft->setObjectName(QString::fromUtf8("horizontalLayoutLeft"));
        pushButtonImport = new QPushButton(layoutWidget);
        pushButtonImport->setObjectName(QString::fromUtf8("pushButtonImport"));
        pushButtonImport->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonImport->sizePolicy().hasHeightForWidth());
        pushButtonImport->setSizePolicy(sizePolicy1);

        horizontalLayoutLeft->addWidget(pushButtonImport);

        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayoutLeft->addItem(horizontalSpacer);


        verticalLayoutLeft->addLayout(horizontalLayoutLeft);

        treeViewImportedData = new QTreeView(layoutWidget);
        treeViewImportedData->setObjectName(QString::fromUtf8("treeViewImportedData"));
        treeViewImportedData->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeViewImportedData->sizePolicy().hasHeightForWidth());
        treeViewImportedData->setSizePolicy(sizePolicy2);
        treeViewImportedData->setAutoFillBackground(false);
        treeViewImportedData->setLineWidth(1);
        treeViewImportedData->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayoutLeft->addWidget(treeViewImportedData);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayoutCenter = new QVBoxLayout(layoutWidget1);
        verticalLayoutCenter->setObjectName(QString::fromUtf8("verticalLayoutCenter"));
        verticalLayoutCenter->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayoutCenter->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutCenter = new QHBoxLayout();
        horizontalLayoutCenter->setObjectName(QString::fromUtf8("horizontalLayoutCenter"));
        comboBoxFieldName = new QComboBox(layoutWidget1);
        comboBoxFieldName->setObjectName(QString::fromUtf8("comboBoxFieldName"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxFieldName->sizePolicy().hasHeightForWidth());
        comboBoxFieldName->setSizePolicy(sizePolicy3);

        horizontalLayoutCenter->addWidget(comboBoxFieldName);

        comboBoxComp = new QComboBox(layoutWidget1);
        comboBoxComp->setObjectName(QString::fromUtf8("comboBoxComp"));
        sizePolicy3.setHeightForWidth(comboBoxComp->sizePolicy().hasHeightForWidth());
        comboBoxComp->setSizePolicy(sizePolicy3);
        comboBoxComp->setMinimumSize(QSize(0, 0));

        horizontalLayoutCenter->addWidget(comboBoxComp);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy4);
        lineEdit->setMaximumSize(QSize(63, 24));
        lineEdit->setBaseSize(QSize(0, 0));

        horizontalLayoutCenter->addWidget(lineEdit);

        labelFileCount = new QLabel(layoutWidget1);
        labelFileCount->setObjectName(QString::fromUtf8("labelFileCount"));
        sizePolicy.setHeightForWidth(labelFileCount->sizePolicy().hasHeightForWidth());
        labelFileCount->setSizePolicy(sizePolicy);

        horizontalLayoutCenter->addWidget(labelFileCount);

        pushButtonFilter = new QPushButton(layoutWidget1);
        pushButtonFilter->setObjectName(QString::fromUtf8("pushButtonFilter"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButtonFilter->sizePolicy().hasHeightForWidth());
        pushButtonFilter->setSizePolicy(sizePolicy5);

        horizontalLayoutCenter->addWidget(pushButtonFilter);


        verticalLayoutCenter->addLayout(horizontalLayoutCenter);

        listViewFolderData = new QListView(layoutWidget1);
        listViewFolderData->setObjectName(QString::fromUtf8("listViewFolderData"));

        verticalLayoutCenter->addWidget(listViewFolderData);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        rightLayout = new QVBoxLayout(layoutWidget2);
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        rightLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        rightLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonExtract = new QPushButton(layoutWidget2);
        pushButtonExtract->setObjectName(QString::fromUtf8("pushButtonExtract"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButtonExtract->sizePolicy().hasHeightForWidth());
        pushButtonExtract->setSizePolicy(sizePolicy6);

        rightLayout->addWidget(pushButtonExtract);

        textEditFileContent = new QTextEdit(layoutWidget2);
        textEditFileContent->setObjectName(QString::fromUtf8("textEditFileContent"));

        rightLayout->addWidget(textEditFileContent);

        splitter->addWidget(layoutWidget2);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 970, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBoxTxt->setText(QApplication::translate("MainWindow", "*.txt", nullptr));
        pushButtonImport->setText(QApplication::translate("MainWindow", "Import", nullptr));
        lineEdit->setText(QString());
        labelFileCount->setText(QString());
        pushButtonFilter->setText(QApplication::translate("MainWindow", "Filter", nullptr));
        pushButtonExtract->setText(QApplication::translate("MainWindow", "Extract All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
