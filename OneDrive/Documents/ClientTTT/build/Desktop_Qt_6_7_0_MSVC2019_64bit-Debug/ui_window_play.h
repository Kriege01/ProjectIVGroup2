/********************************************************************************
** Form generated from reading UI file 'window_play.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PLAY_H
#define UI_WINDOW_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_play
{
public:
    QLabel *p2s;
    QLabel *Game;
    QPushButton *SendnameButton;
    QLabel *me_name_label;
    QLabel *Doyouhavename_label;
    QLabel *label_3;
    QLineEdit *write_name_Edit;
    QLabel *p1s;
    QPushButton *Save;
    QPushButton *Backbutton3;
    QLabel *label_4;
    QLabel *turnLabel;
    QLabel *label_6;
    QLineEdit *ipLine;
    QLineEdit *portLine;
    QLabel *label;
    QLabel *label_2;
    QPushButton *connectButton;
    QPushButton *rematchButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *frame;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;

    void setupUi(QDialog *window_play)
    {
        if (window_play->objectName().isEmpty())
            window_play->setObjectName("window_play");
        window_play->setWindowModality(Qt::NonModal);
        window_play->resize(434, 618);
        window_play->setMouseTracking(false);
        window_play->setAutoFillBackground(false);
        window_play->setStyleSheet(QString::fromUtf8(""));
        window_play->setSizeGripEnabled(false);
        window_play->setModal(false);
        p2s = new QLabel(window_play);
        p2s->setObjectName("p2s");
        p2s->setGeometry(QRect(224, 120, 41, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic")});
        font.setPointSize(35);
        font.setBold(false);
        font.setItalic(false);
        p2s->setFont(font);
        p2s->setStyleSheet(QString::fromUtf8("color: rgb(211, 211, 211);"));
        p2s->setAlignment(Qt::AlignCenter);
        Game = new QLabel(window_play);
        Game->setObjectName("Game");
        Game->setGeometry(QRect(170, 470, 111, 41));
        Game->setStyleSheet(QString::fromUtf8("color: rgb(211, 211, 211);\n"
"font: 10pt \"Siemens AD Sans\";"));
        SendnameButton = new QPushButton(window_play);
        SendnameButton->setObjectName("SendnameButton");
        SendnameButton->setGeometry(QRect(238, 340, 91, 41));
        SendnameButton->setCursor(QCursor(Qt::PointingHandCursor));
        SendnameButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"		\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		background-color: #484848;\n"
"		color: rgb(211, 211, 211);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		image: url(:/Img/back.png);\n"
"		color: #fffffe;\n"
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
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        me_name_label = new QLabel(window_play);
        me_name_label->setObjectName("me_name_label");
        me_name_label->setGeometry(QRect(65, 130, 111, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Siemens AD Sans")});
        font1.setPointSize(25);
        font1.setBold(false);
        font1.setItalic(false);
        me_name_label->setFont(font1);
        me_name_label->setStyleSheet(QString::fromUtf8("font: 25pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);"));
        me_name_label->setAlignment(Qt::AlignCenter);
        Doyouhavename_label = new QLabel(window_play);
        Doyouhavename_label->setObjectName("Doyouhavename_label");
        Doyouhavename_label->setGeometry(QRect(100, 390, 221, 41));
        Doyouhavename_label->setStyleSheet(QString::fromUtf8("color: rgb(211, 211, 211);\n"
"font: 10pt \"Siemens AD Sans\";\n"
""));
        label_3 = new QLabel(window_play);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(265, 130, 111, 45));
        label_3->setFont(font1);
        label_3->setMouseTracking(false);
        label_3->setStyleSheet(QString::fromUtf8("font: 25pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);\n"
""));
        label_3->setAlignment(Qt::AlignCenter);
        write_name_Edit = new QLineEdit(window_play);
        write_name_Edit->setObjectName("write_name_Edit");
        write_name_Edit->setGeometry(QRect(101, 340, 131, 41));
        write_name_Edit->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 15px;"));
        p1s = new QLabel(window_play);
        p1s->setObjectName("p1s");
        p1s->setGeometry(QRect(176, 120, 41, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Yu Gothic")});
        font2.setPointSize(35);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        p1s->setFont(font2);
        p1s->setStyleSheet(QString::fromUtf8("color: rgb(211, 211, 211);"));
        p1s->setAlignment(Qt::AlignCenter);
        Save = new QPushButton(window_play);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(288, 530, 111, 41));
        Save->setCursor(QCursor(Qt::PointingHandCursor));
        Save->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		image: url(:/Img/save.png);\n"
"	\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		\n"
"\n"
"	\n"
"	background-color: rgb(0, 33, 61);\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		image: url(:/Img/save.png);\n"
"		color: #fffffe;\n"
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
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        Backbutton3 = new QPushButton(window_play);
        Backbutton3->setObjectName("Backbutton3");
        Backbutton3->setGeometry(QRect(33, 530, 101, 41));
        Backbutton3->setCursor(QCursor(Qt::PointingHandCursor));
        Backbutton3->setStyleSheet(QString::fromUtf8("\n"
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
"		background-color: rgb(0, 33, 61);\n"
"	\n"
"	color: rgb(170, 0, 0);\n"
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
""));
        label_4 = new QLabel(window_play);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(308, 590, 71, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(121, 120, 117);\n"
"\n"
"font: 10pt \"Siemens AD Sans\";"));
        turnLabel = new QLabel(window_play);
        turnLabel->setObjectName("turnLabel");
        turnLabel->setGeometry(QRect(150, 79, 141, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Siemens Slab Black")});
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setItalic(false);
        turnLabel->setFont(font3);
        turnLabel->setStyleSheet(QString::fromUtf8("font: 30pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);\n"
"font: 18pt \"Siemens Slab Black\";"));
        turnLabel->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(window_play);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(216, 120, 20, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(22);
        font4.setBold(false);
        font4.setItalic(false);
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
""));
        ipLine = new QLineEdit(window_play);
        ipLine->setObjectName("ipLine");
        ipLine->setGeometry(QRect(103, 230, 111, 31));
        ipLine->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 11px;"));
        ipLine->setAlignment(Qt::AlignCenter);
        portLine = new QLineEdit(window_play);
        portLine->setObjectName("portLine");
        portLine->setGeometry(QRect(221, 230, 108, 31));
        portLine->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 11px;"));
        portLine->setAlignment(Qt::AlignCenter);
        label = new QLabel(window_play);
        label->setObjectName("label");
        label->setGeometry(QRect(131, 195, 61, 21));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(window_play);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(244, 190, 61, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Fixedsys")});
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(false);
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"Fixedsys\";\n"
"color: rgb(211, 211, 211);"));
        label_2->setAlignment(Qt::AlignCenter);
        connectButton = new QPushButton(window_play);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(100, 280, 231, 41));
        connectButton->setCursor(QCursor(Qt::PointingHandCursor));
        connectButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"}\n"
"QPushButton:enabled {\n"
"		\n"
"	background-color: rgb(0, 33, 61);\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		image: url(:/Img/back.png);\n"
"		color: #fffffe;\n"
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
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        rematchButton = new QPushButton(window_play);
        rematchButton->setObjectName("rematchButton");
        rematchButton->setGeometry(QRect(157, 530, 111, 41));
        rematchButton->setCursor(QCursor(Qt::PointingHandCursor));
        rematchButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"       border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		font: 9pt \"Fixedsys\";\n"
"		\n"
"\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"		\n"
"	background-color: rgb(168, 172, 198);\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"		\n"
"		background-color: black;\n"
"		image: url(:/Img/back.png);\n"
"		color: #fffffe;\n"
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
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
"\n"
""));
        line = new QFrame(window_play);
        line->setObjectName("line");
        line->setGeometry(QRect(303, 224, 10, 210));
        line->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 15px;\n"
"background-color: rgb(0, 33, 61);\n"
"\n"
"\n"
""));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(window_play);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(221, 224, 10, 210));
        line_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 15px;\n"
"background-color: rgb(0, 33, 61);\n"
"\n"
""));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(window_play);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(139, 225, 10, 210));
        line_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 15px;\n"
"background-color: rgb(0, 33, 61);\n"
"\n"
""));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(window_play);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(108, 244, 230, 10));
        line_5->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 15px;\n"
"\n"
"background-color: rgb(0, 33, 61);\n"
"\n"
""));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(window_play);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(108, 326, 230, 10));
        line_6->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"border-radius: 15px;\n"
"\n"
"background-color: rgb(0, 33, 61);\n"
"\n"
""));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_7 = new QFrame(window_play);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(108, 414, 230, 10));
        line_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Fixedsys\";\n"
"background-color: rgb(0, 33, 61);\n"
"border-radius: 15px;\n"
"\n"
"\n"
""));
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        gridWidget = new QWidget(window_play);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setGeometry(QRect(90, 195, 261, 261));
        QFont font6;
        font6.setBold(false);
        gridWidget->setFont(font6);
        gridWidget->setStyleSheet(QString::fromUtf8("		border-image: url(:/Img/Space..jpg);\n"
"		color: rgb(255, 255, 255);\n"
"      	border-radius: 15px;\n"
"		border-right: 1px solid #aaaaaa;\n"
"		border-bottom: 1px solid #aaaaaa;\n"
"		\n"
"\n"
"\n"
""));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName("gridLayout");
        label_5 = new QLabel(window_play);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 421, 661));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/white.jfif);\n"
"border-image: url(:/Img/Space..jpg);"));
        label_7 = new QLabel(window_play);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(165, 140, 141, 45));
        label_7->setStyleSheet(QString::fromUtf8("font: 25pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);"));
        label_8 = new QLabel(window_play);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(120, 230, 201, 201));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/diagonal.png);"));
        label_9 = new QLabel(window_play);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(120, 230, 201, 201));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/Img/diagonal_right.png);"));
        label_11 = new QLabel(window_play);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(45, 230, 70, 211));
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(window_play);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(127, 230, 70, 211));
        label_13 = new QLabel(window_play);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(206, 230, 70, 211));
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_15 = new QLabel(window_play);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(108, 14, 271, 51));
        label_15->setStyleSheet(QString::fromUtf8("font: 36pt \"Siemens AD Sans\";\n"
"color: rgb(211, 211, 211);"));
        frame = new QLabel(window_play);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-40, -10, 511, 691));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("\n"
"background-origin: content;\n"
"\n"
"\n"
"\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"\n"
"\n"
"  	border-image: url(:/Img/Space..jpg);\n"
"	\n"
"    background-repeat: no-repeat;\n"
"    background-origin: content;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
""));
        label_14 = new QLabel(window_play);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(110, 150, 241, 70));
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_16 = new QLabel(window_play);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(110, 232, 241, 70));
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(window_play);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(110, 315, 241, 70));
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_18 = new QLabel(window_play);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(100, 200, 70, 241));
        label_18->setStyleSheet(QString::fromUtf8(""));
        label_19 = new QLabel(window_play);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(50, 200, 70, 241));
        label_19->setStyleSheet(QString::fromUtf8(""));
        frame->raise();
        gridWidget->raise();
        line_6->raise();
        line_3->raise();
        line_2->raise();
        line->raise();
        line_7->raise();
        line_5->raise();
        label_9->raise();
        label_5->raise();
        label_7->raise();
        write_name_Edit->raise();
        label_8->raise();
        connectButton->raise();
        portLine->raise();
        ipLine->raise();
        label->raise();
        label_2->raise();
        SendnameButton->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_3->raise();
        p2s->raise();
        p1s->raise();
        label_6->raise();
        me_name_label->raise();
        Doyouhavename_label->raise();
        Game->raise();
        Backbutton3->raise();
        rematchButton->raise();
        Save->raise();
        label_4->raise();
        turnLabel->raise();
        label_15->raise();
        label_14->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();

        retranslateUi(window_play);

        QMetaObject::connectSlotsByName(window_play);
    } // setupUi

    void retranslateUi(QDialog *window_play)
    {
        window_play->setWindowTitle(QCoreApplication::translate("window_play", "Dialog", nullptr));
#if QT_CONFIG(accessibility)
        window_play->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        p2s->setText(QCoreApplication::translate("window_play", "0", nullptr));
        Game->setText(QCoreApplication::translate("window_play", "Games played: 0", nullptr));
        SendnameButton->setText(QCoreApplication::translate("window_play", "Send name", nullptr));
        me_name_label->setText(QString());
        Doyouhavename_label->setText(QString());
        label_3->setText(QString());
        write_name_Edit->setText(QString());
        write_name_Edit->setPlaceholderText(QCoreApplication::translate("window_play", "Player", nullptr));
        p1s->setText(QCoreApplication::translate("window_play", "0", nullptr));
        Save->setText(QString());
        Backbutton3->setText(QString());
        label_4->setText(QString());
        turnLabel->setText(QString());
        label_6->setText(QCoreApplication::translate("window_play", ":", nullptr));
        ipLine->setText(QCoreApplication::translate("window_play", "127.0.0.1", nullptr));
        portLine->setText(QCoreApplication::translate("window_play", "2323", nullptr));
        label->setText(QCoreApplication::translate("window_play", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("window_play", "Port", nullptr));
        connectButton->setText(QCoreApplication::translate("window_play", "Connect", nullptr));
        rematchButton->setText(QCoreApplication::translate("window_play", "Rematch", nullptr));
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("window_play", "Settings", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_15->setText(QCoreApplication::translate("window_play", "TIC TAC TOE", nullptr));
#if QT_CONFIG(accessibility)
        frame->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        frame->setText(QString());
        label_14->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class window_play: public Ui_window_play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PLAY_H
