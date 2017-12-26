#include <QApplication>
#include "Game.h"
#include "dialog.h"
#include <QTime>
#include <StartGame.h>
/*
Tutorial Topics:
-parents
-QGraphicsTextItem, setPlainText(), setFont(),setDefaultTextColor()
*/

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

     qsrand(QDateTime::currentMSecsSinceEpoch());
    StartGame * startGame = new StartGame;


    startGame->show();





    return a.exec();
}
