#include "ProjectIV.h"

using namespace std;

ProjectIV::ProjectIV(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   

    QObject::connect(ui.registerButton, SIGNAL(clicked()), this, SLOT(registerPageWidget()));
    QObject::connect(ui.loginPageButton, SIGNAL(clicked()), this, SLOT(loginPageWidget()));
    QObject::connect(ui.loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
    

    //TICTACTOE BUTTONS
    //ROW 1
    connect(ui.button00, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    connect(ui.button01, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    connect(ui.button02, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    //ROW 2
    connect(ui.button10, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    connect(ui.button11, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    connect(ui.button12, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    //ROW 3
    connect(ui.button20, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    connect(ui.button21, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
    connect(ui.button22, &QPushButton::clicked, this, &ProjectIV::onGameButtonClicked);
}


//PAGE SETTERS 
void ProjectIV::loginPageWidget()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void ProjectIV::registerPageWidget()
{
    ui.stackedWidget->setCurrentIndex(1);
}

void ProjectIV::menuPageWidget()
{
    ui.stackedWidget->setCurrentIndex(2);
}

//TO LOGIN USERNAME AND PASSWORD MUST BE FILLED
void ProjectIV::loginButtonClicked() //WIP (NEED TO INCORPORATE FILES)
{

    string username = ui.usernameLine->text().toStdString();
    string password = ui.passwordLine->text().toStdString();

    bool loggedIn = loginUser(username, password);

    loggedIn = true;

    if (loggedIn == true)
    {
        menuPageWidget();
    }
}


//TICTACTOE 
void ProjectIV::onGameButtonClicked() 
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button)
    {
        //retrieving the row and column from the button's name
        int row = button->objectName().mid(6, 1).toInt();
        int col = button->objectName().mid(7, 1).toInt();

        button->setText(QString(currentPlayer));  // Set this to "X" or "O" depending on the current player
        button->setEnabled(false);
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

   char winner = gameLogic();

    if (winner != ' ') // There's a winner
    {
        resetGame(); // Reset the game for the next round
    }
}
char ProjectIV::gameLogic()
{
    auto getButtonText = [this](int row, int col) -> QString {
        QPushButton* button = nullptr;
        if (row == 0 && col == 0) button = ui.button00;
        else if (row == 0 && col == 1) button = ui.button01;
        else if (row == 0 && col == 2) button = ui.button02;
        else if (row == 1 && col == 0) button = ui.button10;
        else if (row == 1 && col == 1) button = ui.button11;
        else if (row == 1 && col == 2) button = ui.button12;
        else if (row == 2 && col == 0) button = ui.button20;
        else if (row == 2 && col == 1) button = ui.button21;
        else if (row == 2 && col == 2) button = ui.button22;

        return button ? button->text() : QString();
        };

    // Check rows for winner
    for (int row = 0; row < 3; ++row)
    {
        if (getButtonText(row, 0) == getButtonText(row, 1) &&
            getButtonText(row, 1) == getButtonText(row, 2) &&
            !getButtonText(row, 0).isEmpty())
        {
            return getButtonText(row, 0).toStdString()[0];
        }
    }

    // Check columns for winner
    for (int col = 0; col < 3; ++col)
    {
        if (getButtonText(0, col) == getButtonText(1, col) &&
            getButtonText(1, col) == getButtonText(2, col) &&
            !getButtonText(0, col).isEmpty())
        {
            return getButtonText(0, col).toStdString()[0];
        }
    }

    // Check diagonals for winner
    if (getButtonText(0, 0) == getButtonText(1, 1) &&
        getButtonText(1, 1) == getButtonText(2, 2) &&
        !getButtonText(0, 0).isEmpty())
    {
        return getButtonText(0, 0).toStdString()[0];
    }
    if (getButtonText(0, 2) == getButtonText(1, 1) &&
        getButtonText(1, 1) == getButtonText(2, 0) &&
        !getButtonText(0, 2).isEmpty())
    {
        return getButtonText(0, 2).toStdString()[0];
    }

    // No winner yet
    return ' ';
}

void ProjectIV::resetGame()
{
    currentPlayer = 'X';

    ui.button00->setEnabled(true); ui.button00->setText("");
    ui.button01->setEnabled(true); ui.button01->setText("");
    ui.button02->setEnabled(true); ui.button02->setText("");
    ui.button10->setEnabled(true); ui.button10->setText("");
    ui.button11->setEnabled(true); ui.button11->setText("");
    ui.button12->setEnabled(true); ui.button12->setText("");
    ui.button20->setEnabled(true); ui.button20->setText("");
    ui.button21->setEnabled(true); ui.button21->setText("");
    ui.button22->setEnabled(true); ui.button22->setText("");
}


//SERVER CLIENT - TICTACTOE



ProjectIV::~ProjectIV()
{







}
