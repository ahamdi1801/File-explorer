/********************************************************************************
** Form generated from reading UI file 'second_window_class.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_WINDOW_CLASS_H
#define UI_SECOND_WINDOW_CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QToolButton *toolButtonCheckboxes;
    QPushButton *pushButtonShowMsg;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelMsg;
    QPushButton *pushButtonBrowseImg;
    QGraphicsView *graphicsViewImg;
    QPushButton *pushButtonShowSecond;
    QGroupBox *groupBoxSecondImg;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonBrowseSecond;
    QLabel *labelImg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(447, 427);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        horizontalLayout->addWidget(lineEditName);

        toolButtonCheckboxes = new QToolButton(centralwidget);
        toolButtonCheckboxes->setObjectName(QString::fromUtf8("toolButtonCheckboxes"));

        horizontalLayout->addWidget(toolButtonCheckboxes);

        pushButtonShowMsg = new QPushButton(centralwidget);
        pushButtonShowMsg->setObjectName(QString::fromUtf8("pushButtonShowMsg"));
        pushButtonShowMsg->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(pushButtonShowMsg);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelMsg = new QLabel(centralwidget);
        labelMsg->setObjectName(QString::fromUtf8("labelMsg"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelMsg->sizePolicy().hasHeightForWidth());
        labelMsg->setSizePolicy(sizePolicy);
        labelMsg->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(labelMsg);

        pushButtonBrowseImg = new QPushButton(centralwidget);
        pushButtonBrowseImg->setObjectName(QString::fromUtf8("pushButtonBrowseImg"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonBrowseImg->sizePolicy().hasHeightForWidth());
        pushButtonBrowseImg->setSizePolicy(sizePolicy1);
        pushButtonBrowseImg->setMinimumSize(QSize(80, 0));
        pushButtonBrowseImg->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(pushButtonBrowseImg);


        verticalLayout_2->addLayout(horizontalLayout_2);

        graphicsViewImg = new QGraphicsView(centralwidget);
        graphicsViewImg->setObjectName(QString::fromUtf8("graphicsViewImg"));

        verticalLayout_2->addWidget(graphicsViewImg);

        pushButtonShowSecond = new QPushButton(centralwidget);
        pushButtonShowSecond->setObjectName(QString::fromUtf8("pushButtonShowSecond"));

        verticalLayout_2->addWidget(pushButtonShowSecond);

        groupBoxSecondImg = new QGroupBox(centralwidget);
        groupBoxSecondImg->setObjectName(QString::fromUtf8("groupBoxSecondImg"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBoxSecondImg->sizePolicy().hasHeightForWidth());
        groupBoxSecondImg->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(groupBoxSecondImg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButtonBrowseSecond = new QPushButton(groupBoxSecondImg);
        pushButtonBrowseSecond->setObjectName(QString::fromUtf8("pushButtonBrowseSecond"));

        verticalLayout->addWidget(pushButtonBrowseSecond);

        labelImg = new QLabel(groupBoxSecondImg);
        labelImg->setObjectName(QString::fromUtf8("labelImg"));
        sizePolicy2.setHeightForWidth(labelImg->sizePolicy().hasHeightForWidth());
        labelImg->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(labelImg);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBoxSecondImg);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 447, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Name:", nullptr));
        lineEditName->setPlaceholderText(QApplication::translate("MainWindow", "Enter your name...", nullptr));
        toolButtonCheckboxes->setText(QApplication::translate("MainWindow", "...", nullptr));
        pushButtonShowMsg->setText(QApplication::translate("MainWindow", "Show Message", nullptr));
        labelMsg->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButtonBrowseImg->setText(QApplication::translate("MainWindow", "Browse", nullptr));
        pushButtonShowSecond->setText(QApplication::translate("MainWindow", "Show Second", nullptr));
        groupBoxSecondImg->setTitle(QApplication::translate("MainWindow", "Second Image", nullptr));
        pushButtonBrowseSecond->setText(QApplication::translate("MainWindow", "Browse", nullptr));
        labelImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_WINDOW_CLASS_H
