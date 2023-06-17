/********************************************************************************
** Form generated from reading UI file 'main_window_example.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_EXAMPLE_H
#define UI_MAIN_WINDOW_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QCommandLinkButton *commandLinkButtonBrowse;
    QSplitter *splitter;
    QTableView *tableViewFileList;
    QTextBrowser *textBrowserFileContent;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSecondWindow;
    QPushButton *pushButtonShowID;
    QSpacerItem *horizontalSpacer;
    QLabel *labelID;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(600, 400);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        commandLinkButtonBrowse = new QCommandLinkButton(centralWidget);
        commandLinkButtonBrowse->setObjectName(QString::fromUtf8("commandLinkButtonBrowse"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commandLinkButtonBrowse->sizePolicy().hasHeightForWidth());
        commandLinkButtonBrowse->setSizePolicy(sizePolicy);

        gridLayout->addWidget(commandLinkButtonBrowse, 0, 0, 1, 1);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setOrientation(Qt::Horizontal);
        tableViewFileList = new QTableView(splitter);
        tableViewFileList->setObjectName(QString::fromUtf8("tableViewFileList"));
        tableViewFileList->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);
        tableViewFileList->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewFileList->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(tableViewFileList);
        textBrowserFileContent = new QTextBrowser(splitter);
        textBrowserFileContent->setObjectName(QString::fromUtf8("textBrowserFileContent"));
        splitter->addWidget(textBrowserFileContent);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        pushButtonSecondWindow = new QPushButton(centralWidget);
        pushButtonSecondWindow->setObjectName(QString::fromUtf8("pushButtonSecondWindow"));

        horizontalLayout->addWidget(pushButtonSecondWindow);

        pushButtonShowID = new QPushButton(centralWidget);
        pushButtonShowID->setObjectName(QString::fromUtf8("pushButtonShowID"));

        horizontalLayout->addWidget(pushButtonShowID);

        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelID = new QLabel(centralWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));

        horizontalLayout->addWidget(labelID);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        commandLinkButtonBrowse->setText(QApplication::translate("MainWindowClass", "Browse", nullptr));
        pushButtonSecondWindow->setText(QApplication::translate("MainWindowClass", "Second Window", nullptr));
        pushButtonShowID->setText(QApplication::translate("MainWindowClass", "Show ID", nullptr));
        labelID->setText(QApplication::translate("MainWindowClass", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_EXAMPLE_H
