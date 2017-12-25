#include "Bomb.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // qrand() -> really large int
#include "Game.h"
#include <QDebug>
#include "Player.h"
#include <typeinfo>

extern Game * game;

Bomb::Bomb(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = qrand() % 700;
    setPos(random_number,0);

    // drew the bomb
    setPixmap(QPixmap(":/images/assets/bomb.png"));
    setScale(0.4);

    // make/connect a timer to move() the fruit every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bomb::move(){
    // move fruit down
    setPos(x(),y()+5);


    // destroy fruit when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        scene()->removeItem(this);
        delete this;
    }


       QList<QGraphicsItem *> colliding_items = collidingItems();
       for (int i = 0, n = colliding_items.size(); i < n; ++i){
           if (typeid(*(colliding_items[i])) == typeid(Player)){

                game->health->decrease();
               scene()->removeItem(this);
               delete this;
               return;
           }
       }
}
