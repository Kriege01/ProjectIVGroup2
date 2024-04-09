#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <unordered_map>
#include <QFile>
#include <QTextStream>
#include "gamelogic.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    void sendGamesPlayed();
    int cross;
    int sendcross;

private:
    QVector<QTcpSocket*> sockets;
    QVector<int> id;
    QVector<int> id2;
    QVector<QVector<char>> board;
    std::unordered_map<int, int> rematch;
    QByteArray data;

    int turn;
    int win;
    int gamesPlayed;
    int scorePlayer2for1 =0;
    int scorePlayer1for2 =0;
    int scorePlayer1;
    int scorePlayer2;
    int scoreid;
    QString msg1;
    QString msg2;
    GameLogic* gameLogic;
    std::unordered_map<QString, QString> credentials;

    void loadCredentials();
    void sendCredentials(QTcpSocket* socket);
    void send();
    void send2();
    void newGame();
    void deleteConnection();

public slots:
    void incomingConnection(qintptr descriptor);
    void slotReadyRead();
};

#endif // SERVER_H
