/********************************************************************************
** Form generated from reading UI file 'menu1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU1_H
#define UI_MENU1_H

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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(599, 417);
        Menu->setStyleSheet(QString::fromUtf8(""));
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
"		background-color: #5f5f5f;\n"
"\n"
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 20, 221, 61));
        label->setStyleSheet(QString::fromUtf8("font: 36pt \"Siemens AD Sans\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(430, 80, 141, 151));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/Img/Rocket.gif);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 100, 101, 81));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/86682.thumb.gif.957a83f36e8762471d29bc82be60458d.gif);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(450, 260, 81, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 280, 121, 111));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Img/86682.thumb.gif.957a83f36e8762471d29bc82be60458d.gif")));
        label_4->setScaledContents(true);
        Menu->setCentralWidget(centralwidget);

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
        label->setText(QCoreApplication::translate("Menu", "TIC TAC TOE", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_5->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU1_H
