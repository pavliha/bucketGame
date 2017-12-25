#include <QApplication>
#include "Game.h"
#include "dialog.h"
#include <QTime>
/*
Tutorial Topics:
-parents
-QGraphicsTextItem, setPlainText(), setFont(),setDefaultTextColor()
*/

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    qsrand(QDateTime::currentMSecsSinceEpoch());

    game = new Game();

    return a.exec();
}
