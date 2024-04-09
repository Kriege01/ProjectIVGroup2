#include "server.h"
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <QDataStream>
#include "gamelogic.h"
Server::Server()
{
    listen(QHostAddress::Any, 2323);
    id = {1,0};
    id2 = {1,0};
    turn = win = 0;
    qDebug() << "Started";
    gamesPlayed = 0;
    scorePlayer1 =0 ;
    scorePlayer2 =0 ;
    scoreid=3;
    gameLogic = new GameLogic(board);
    cross=0;

    // Load credentials file
    loadCredentials();


}

void Server::loadCredentials() {
    QFile file("credentials.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(":");
            if (parts.size() == 2) {
                credentials[parts[0]] = parts[1];
            }
        }
        file.close();
    }
}

void Server::sendCredentials(QTcpSocket* socket) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);

    out << QString("credentials"); // Send a QString to indicate that credentials are being sent

    // Serialize credentials map manually
    out << quint32(credentials.size()); // Send the size of the map first
    for (const auto& pair : credentials) {
        out << pair.first;  // Send the key
        out << pair.second; // Send the value
    }

    socket->write(data);
}

void Server::send()                                  //Function for sending informations to clients
{
    data.clear();

    for(auto &socket : sockets)
    {
        QDataStream out(&data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_3);

        out << board;
        out << int(socket->socketDescriptor() == sockets[id[turn]]->socketDescriptor());
        out << win;
        out << cross;
        out << gamesPlayed;
        out << scorePlayer1;
        out << scorePlayer2;

        if (socket->socketDescriptor() == sockets[id2[0]]->socketDescriptor()) {
            out << scoreid;
        } else {
            out << 0;
        }

        if (socket->socketDescriptor() == sockets[id2[0]]->socketDescriptor()) {                //Send name to client with id0
            out << msg1;
        }

        if (socket->socketDescriptor() == sockets[id2[1]]->socketDescriptor()) {                //Send name to client with id1
            out << msg2;
        }


        socket->write(data);
    }
}


void Server::newGame() {                                                  // Function for making new game and swapping players
    gameLogic->resetGame(gamesPlayed, turn, win, rematch);


    std::swap(id[0], id[1]);
    qDebug() << "Games Played: " << gamesPlayed;
}


void Server::deleteConnection() {
    auto socket = dynamic_cast<QTcpSocket*>(sender());
    sockets.erase(std::find(sockets.begin(), sockets.end(), socket));
    qDebug() << "Disconnected: " << socket->socketDescriptor();
    socket->deleteLater();
}

void Server::incomingConnection(qintptr descriptor) {
    auto socket = new QTcpSocket;
    socket->setSocketDescriptor(descriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::deleteConnection);

    if (sockets.size() < 2) {
        sockets.push_back(socket);
        if (sockets.size() == 2) {
            newGame();
            send();
        }
        qDebug() << "Connected: " << descriptor;

        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_6_3);

        // Send credentials to the client
        sendCredentials(socket);
    } else {
        socket->disconnect();
    }
}

void Server::slotReadyRead()                                                                  // Function for reading informations comming from clients
{
    auto socket = dynamic_cast<QTcpSocket*>(sender());
    auto desc = socket->socketDescriptor();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_3);

    if (in.status() != QDataStream::Ok)
    {
        qDebug() << "Error reading";
        return;
    }


    QString action;
    in >> action;

    qDebug() << action << sockets.size();

    if (action == "place" && sockets.size() == 2)                          // Income move from player boards
    {
        int i, j;
        in >> i >> j ;
        if (i >= 0 && i < 3 && j >= 0 && j < 3 &&
            board[i][j] == '.' && !win &&
            desc == sockets[id[turn]]->socketDescriptor())
        {
            board[i][j] = (turn == 0) ? 'X' : 'O';
            turn = (turn + 1) % 2;
            win = gameLogic->checkWin();
            gameLogic->setCross(cross);        //Skusam spustit setCross
            qDebug() << "win " << win;
            qDebug() << "turn " << turn;
            qDebug() << "Cross number: " << cross;

            if (win == 1)

            {
                if (gamesPlayed % 2 != 0)                                   // Increment score to players after win
                {
                    if (turn == 1)
                    {
                        scorePlayer1++;
                        qDebug() << "Player 1: " << scorePlayer1;
                    }
                    else
                    {
                        scorePlayer2++;
                        qDebug() << "Player 2: " << scorePlayer2;
                    }
                }
                else
                {
                    if (turn == 1)
                    {
                        scorePlayer2++;
                        qDebug() << "Player 2: " << scorePlayer2;
                    }
                    else
                    {
                        scorePlayer1++;
                        qDebug() << "Player 1: " << scorePlayer1;
                    }
                }
            }

            send();
        }
    }
    else if (action == "rematch" && win)                                   // Ensure rematch for both clients
    {
        rematch[socket->socketDescriptor()] = 1;
        int sum = 0;

        for (auto &[key, val] : rematch)
        {
            sum += val;
        }

        if (sum == 2)
        {
            newGame();
            send();
        }
    }
    else if (action == "chat")                                                              // Using for changing names
    {
        QString message;
        in >> message;
        if (socket->socketDescriptor() == sockets[id2[1]]->socketDescriptor()) {
            msg1=message;
            send();
        }

        if (socket->socketDescriptor() == sockets[id2[0]]->socketDescriptor()) {
            msg2=message;
            send();

        }
    }
}






