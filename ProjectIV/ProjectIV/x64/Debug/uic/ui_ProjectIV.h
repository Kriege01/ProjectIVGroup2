/********************************************************************************
** Form generated from reading UI file 'ProjectIV.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTIV_H
#define UI_PROJECTIV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectIVClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QLineEdit *usernameLine;
    QLineEdit *passwordLine;
    QWidget *registerPage;
    QPushButton *loginPageButton;
    QLabel *label;
    QWidget *menuPage;
    QPushButton *pushButton;
    QFrame *frame_3;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QWidget *page;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button22;
    QPushButton *button02;
    QPushButton *button11;
    QPushButton *button00;
    QPushButton *button10;
    QPushButton *button12;
    QPushButton *button20;
    QPushButton *button01;
    QPushButton *button21;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectIVClass)
    {
        if (ProjectIVClass->objectName().isEmpty())
            ProjectIVClass->setObjectName("ProjectIVClass");
        ProjectIVClass->resize(925, 667);
        centralWidget = new QWidget(ProjectIVClass);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 921, 631));
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(42, 42, 63);"));
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        registerButton = new QPushButton(loginPage);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(350, 310, 91, 24));
        registerButton->setStyleSheet(QString::fromUtf8("\n"
"border: 2px solid rgb(37,39,48);\n"
"border-radius: 10px;\n"
"color: #FFF"));
        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(490, 310, 91, 24));
        loginButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(37,39,48);\n"
"border-radius: 10px;\n"
"color: #FFF\n"
""));
        usernameLine = new QLineEdit(loginPage);
        usernameLine->setObjectName("usernameLine");
        usernameLine->setGeometry(QRect(350, 180, 231, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("STXihei")});
        font.setPointSize(11);
        font.setBold(true);
        usernameLine->setFont(font);
        usernameLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	\n"
"border: 2px solid rgb(18, 18, 27);\n"
"border-radius: 10px;\n"
"color: #FFF;\n"
"padding-left: 20px;\n"
"padding-right: 20px;\n"
"\n"
"	background-color: rgb(42, 42, 63);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(42, 42, 63);\n"
"}"));
        passwordLine = new QLineEdit(loginPage);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setGeometry(QRect(350, 230, 231, 31));
        passwordLine->setFont(font);
        passwordLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 2px solid rgb(18, 18, 27);\n"
"border-radius: 10px;\n"
"color: #FFF;\n"
"padding-left: 20px;\n"
"padding-right: 20px;\n"
"\n"
"	background-color: rgb(42, 42, 63);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(42, 42, 63);\n"
"}"));
        stackedWidget->addWidget(loginPage);
        registerPage = new QWidget();
        registerPage->setObjectName("registerPage");
        loginPageButton = new QPushButton(registerPage);
        loginPageButton->setObjectName("loginPageButton");
        loginPageButton->setGeometry(QRect(410, 290, 75, 24));
        label = new QLabel(registerPage);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 220, 41, 31));
        stackedWidget->addWidget(registerPage);
        menuPage = new QWidget();
        menuPage->setObjectName("menuPage");
        pushButton = new QPushButton(menuPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 150, 121, 111));
        frame_3 = new QFrame(menuPage);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(60, 10, 121, 121));
        QFont font1;
        font1.setBold(false);
        frame_3->setFont(font1);
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 104, 255);\n"
"border: 2px solid;\n"
"\n"
"border-radius: 58px;\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(menuPage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(680, 50, 221, 491));
        listWidget = new QListWidget(groupBox);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 20, 201, 461));
        lineEdit = new QLineEdit(menuPage);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(680, 560, 171, 22));
        label_4 = new QLabel(menuPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(680, 540, 91, 16));
        pushButton_2 = new QPushButton(menuPage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(860, 560, 41, 24));
        stackedWidget->addWidget(menuPage);
        page = new QWidget();
        page->setObjectName("page");
        gridLayoutWidget = new QWidget(page);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(240, 100, 351, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(9);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button22 = new QPushButton(gridLayoutWidget);
        button22->setObjectName("button22");

        gridLayout->addWidget(button22, 2, 2, 1, 1);

        button02 = new QPushButton(gridLayoutWidget);
        button02->setObjectName("button02");

        gridLayout->addWidget(button02, 0, 2, 1, 1);

        button11 = new QPushButton(gridLayoutWidget);
        button11->setObjectName("button11");

        gridLayout->addWidget(button11, 1, 1, 1, 1);

        button00 = new QPushButton(gridLayoutWidget);
        button00->setObjectName("button00");

        gridLayout->addWidget(button00, 0, 0, 1, 1);

        button10 = new QPushButton(gridLayoutWidget);
        button10->setObjectName("button10");

        gridLayout->addWidget(button10, 1, 0, 1, 1);

        button12 = new QPushButton(gridLayoutWidget);
        button12->setObjectName("button12");

        gridLayout->addWidget(button12, 1, 2, 1, 1);

        button20 = new QPushButton(gridLayoutWidget);
        button20->setObjectName("button20");

        gridLayout->addWidget(button20, 2, 0, 1, 1);

        button01 = new QPushButton(gridLayoutWidget);
        button01->setObjectName("button01");

        gridLayout->addWidget(button01, 0, 1, 1, 1);

        button21 = new QPushButton(gridLayoutWidget);
        button21->setObjectName("button21");

        gridLayout->addWidget(button21, 2, 1, 1, 1);

        stackedWidget->addWidget(page);
        ProjectIVClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjectIVClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 925, 22));
        ProjectIVClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjectIVClass);
        mainToolBar->setObjectName("mainToolBar");
        ProjectIVClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjectIVClass);
        statusBar->setObjectName("statusBar");
        ProjectIVClass->setStatusBar(statusBar);

        retranslateUi(ProjectIVClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ProjectIVClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectIVClass)
    {
        ProjectIVClass->setWindowTitle(QCoreApplication::translate("ProjectIVClass", "ProjectIV", nullptr));
        registerButton->setText(QCoreApplication::translate("ProjectIVClass", "Register Page", nullptr));
        loginButton->setText(QCoreApplication::translate("ProjectIVClass", "Login", nullptr));
        usernameLine->setText(QString());
        usernameLine->setPlaceholderText(QCoreApplication::translate("ProjectIVClass", "Username", nullptr));
        passwordLine->setPlaceholderText(QCoreApplication::translate("ProjectIVClass", "Password", nullptr));
        loginPageButton->setText(QCoreApplication::translate("ProjectIVClass", "Login Page", nullptr));
        label->setText(QCoreApplication::translate("ProjectIVClass", "TEST", nullptr));
        pushButton->setText(QCoreApplication::translate("ProjectIVClass", "TicTacToe", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ProjectIVClass", "ChatRoom", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("ProjectIVClass", "Client 1: Hi                              16:42", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_4->setText(QCoreApplication::translate("ProjectIVClass", "Send A Message", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ProjectIVClass", "Send", nullptr));
        button22->setText(QString());
        button02->setText(QString());
        button11->setText(QString());
        button00->setText(QString());
        button10->setText(QString());
        button12->setText(QString());
        button20->setText(QString());
        button01->setText(QString());
        button21->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProjectIVClass: public Ui_ProjectIVClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTIV_H
