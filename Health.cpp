#include "Health.h"
#include <QFont>
#include <QDebug>
#include "dialog.h"
#include "Game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2

    if(game->health->getHealth() <0 && !game->closed){

        game->closed = true;
        game->showDialog();
        game->close();

    }
}

int Health::getHealth(){
    return health;
}
