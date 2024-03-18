#pragma once

#include <QtWidgets/QMainWindow>
#include "UserAuthentication.h"
#include "ui_ProjectIV.h"

#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <QtGui>
#include <qstackedwidget.h>
#include <qlineedit.h>


class ProjectIV : public QMainWindow
{
    Q_OBJECT

public:
    ProjectIV(QWidget *parent = nullptr);
    ~ProjectIV();
    QStackedWidget* stackedWidget;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;

    //SERVER CLIENT
    SOCKET tcpSocket;

    //TICTACTOE
    char currentPlayer = 'X';

    char gameLogic();
    void resetGame();
  
private:
    Ui::ProjectIVClass ui;


    //TICTACTOE
   

public slots:
    void loginPageWidget();
    void registerPageWidget();
    void menuPageWidget();


    void loginButtonClicked();

    //TICTACTOE
    void onGameButtonClicked();
    

};
