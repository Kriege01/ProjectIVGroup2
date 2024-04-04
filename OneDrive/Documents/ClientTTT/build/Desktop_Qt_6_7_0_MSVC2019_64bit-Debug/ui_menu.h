/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *Startgamebtn;
    QPushButton *Rules;
    QPushButton *Scoreboard;
    QPushButton *Quit;
    QLabel *label1;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(632, 428);
        Menu->setStyleSheet(QString::fromUtf8(""));
        Menu->setIconSize(QSize(30, 30));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName("centralwidget");
        Startgamebtn = new QPushButton(centralwidget);
        Startgamebtn->setObjectName("Startgamebtn");
        Startgamebtn->setGeometry(QRect(210, 110, 171, 41));
        Startgamebtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		background-color: black;\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"		background-color: #E1F4FF;\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        Rules = new QPushButton(centralwidget);
        Rules->setObjectName("Rules");
        Rules->setGeometry(QRect(210, 160, 171, 41));
        Rules->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		background-color: black;\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"		background-color: #E1F4FF;\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        Scoreboard = new QPushButton(centralwidget);
        Scoreboard->setObjectName("Scoreboard");
        Scoreboard->setGeometry(QRect(210, 210, 171, 41));
        Scoreboard->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		background-color: black;\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"		background-color: #E1F4FF;\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        Quit = new QPushButton(centralwidget);
        Quit->setObjectName("Quit");
        Quit->setGeometry(QRect(210, 260, 171, 41));
        Quit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		background-color: black;\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"		background-color: #E1F4FF;\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        label1 = new QLabel(centralwidget);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(190, 20, 221, 61));
        label1->setStyleSheet(QString::fromUtf8("font: 36pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 180, 141, 151));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/Img/Rocket.gif);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 170, 81, 131));
        label->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-8, -10, 641, 451));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/Space..jpg);"));
        Menu->setCentralWidget(centralwidget);
        label_3->raise();
        Startgamebtn->raise();
        Rules->raise();
        Scoreboard->raise();
        Quit->raise();
        label1->raise();
        label_2->raise();
        label->raise();

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        Startgamebtn->setText(QCoreApplication::translate("Menu", "START GAME", nullptr));
        Rules->setText(QCoreApplication::translate("Menu", "RULES", nullptr));
        Scoreboard->setText(QCoreApplication::translate("Menu", "SCOREBOARD", nullptr));
        Quit->setText(QCoreApplication::translate("Menu", "QUIT", nullptr));
        label1->setText(QCoreApplication::translate("Menu", "TIC TAC TOE", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
