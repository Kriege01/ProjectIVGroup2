/********************************************************************************
** Form generated from reading UI file 'window_scoreboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_SCOREBOARD_H
#define UI_WINDOW_SCOREBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_window_scoreboard
{
public:
    QPushButton *Backbutton2;
    QLabel *label2;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QLabel *label1;

    void setupUi(QDialog *window_scoreboard)
    {
        if (window_scoreboard->objectName().isEmpty())
            window_scoreboard->setObjectName("window_scoreboard");
        window_scoreboard->resize(587, 430);
        window_scoreboard->setStyleSheet(QString::fromUtf8(""));
        Backbutton2 = new QPushButton(window_scoreboard);
        Backbutton2->setObjectName("Backbutton2");
        Backbutton2->setGeometry(QRect(20, 30, 71, 31));
        Backbutton2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		image: url(:/Img/back.png);\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		background-color: rgb(0, 33, 61);\n"
"		color: rgb(170, 0, 0);\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: white;\n"
"		image: url(:/Img/back.png);\n"
"		color: #ffffff;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"		background-color: #696c9d;\n"
"\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #ffffff;\n"
"\n"
"		color: #ffffff;\n"
"}\n"
"\n"
"\n"
""));
        label2 = new QLabel(window_scoreboard);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(110, 190, 341, 171));
        label2->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);\n"
""));
        label = new QLabel(window_scoreboard);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 100, 111, 51));
        label->setStyleSheet(QString::fromUtf8("font: 80pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);\n"
"\n"
""));
        label_2 = new QLabel(window_scoreboard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 160, 331, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);"));
        line = new QFrame(window_scoreboard);
        line->setObjectName("line");
        line->setGeometry(QRect(113, 180, 311, 16));
        line->setStyleSheet(QString::fromUtf8("color: rgb(211, 211, 211);"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_3 = new QLabel(window_scoreboard);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, -1, 591, 431));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/Space..jpg);"));
        label1 = new QLabel(window_scoreboard);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(180, 30, 301, 61));
        label1->setStyleSheet(QString::fromUtf8("font: 36pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);"));
        label_3->raise();
        Backbutton2->raise();
        label2->raise();
        label->raise();
        label_2->raise();
        line->raise();
        label1->raise();

        retranslateUi(window_scoreboard);

        QMetaObject::connectSlotsByName(window_scoreboard);
    } // setupUi

    void retranslateUi(QDialog *window_scoreboard)
    {
        window_scoreboard->setWindowTitle(QCoreApplication::translate("window_scoreboard", "Dialog", nullptr));
        Backbutton2->setText(QString());
        label2->setText(QString());
        label->setText(QCoreApplication::translate("window_scoreboard", "SCOREBOARD", nullptr));
        label_2->setText(QCoreApplication::translate("window_scoreboard", "No.  Score  Player1   Player2", nullptr));
        label_3->setText(QString());
        label1->setText(QCoreApplication::translate("window_scoreboard", "TIC TAC TOE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_scoreboard: public Ui_window_scoreboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_SCOREBOARD_H
