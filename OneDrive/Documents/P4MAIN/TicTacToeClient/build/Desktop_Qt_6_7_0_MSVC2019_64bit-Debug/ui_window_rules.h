/********************************************************************************
** Form generated from reading UI file 'window_rules.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_RULES_H
#define UI_WINDOW_RULES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_window_rules
{
public:
    QLabel *label;
    QPushButton *Backbutton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label1;

    void setupUi(QDialog *window_rules)
    {
        if (window_rules->objectName().isEmpty())
            window_rules->setObjectName("window_rules");
        window_rules->resize(646, 414);
        window_rules->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(window_rules);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 140, 561, 161));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);\n"
""));
        Backbutton = new QPushButton(window_rules);
        Backbutton->setObjectName("Backbutton");
        Backbutton->setGeometry(QRect(20, 30, 71, 31));
        Backbutton->setStyleSheet(QString::fromUtf8("\n"
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
"		\n"
"		\n"
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
        label_2 = new QLabel(window_rules);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 90, 71, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 36pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);\n"
"\n"
""));
        label_3 = new QLabel(window_rules);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, -1, 651, 421));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/Space..jpg);"));
        label1 = new QLabel(window_rules);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(198, 24, 301, 61));
        label1->setStyleSheet(QString::fromUtf8("font: 36pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);"));
        label_3->raise();
        label->raise();
        Backbutton->raise();
        label_2->raise();
        label1->raise();

        retranslateUi(window_rules);

        QMetaObject::connectSlotsByName(window_rules);
    } // setupUi

    void retranslateUi(QDialog *window_rules)
    {
        window_rules->setWindowTitle(QCoreApplication::translate("window_rules", "Dialog", nullptr));
        label->setText(QString());
        Backbutton->setText(QString());
        label_2->setText(QCoreApplication::translate("window_rules", " RULES", nullptr));
        label_3->setText(QString());
        label1->setText(QCoreApplication::translate("window_rules", "TIC TAC TOE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_rules: public Ui_window_rules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_RULES_H
