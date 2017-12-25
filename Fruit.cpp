#include "Fruit.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // qrand() -> really large int
#include "Game.h"
#include <QDebug>
#include "Bomb.h"
#include <QString>
#include "dialog.h"
#include <QDebug>
#include <typeinfo>

extern Game * game;

int Fruit::lastFruit = 100;

Fruit::Fruit(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random x position
    int random_number = qrand() % 700;
    setPos(random_number,0);

    int random_fruit;
    do
    {
    random_fruit = qrand() % 3;
    }while(random_fruit == lastFruit);

    lastFruit = random_fruit;


    QString fruits[4] = {
        ":/images/assets/apple.png",
        ":/images/assets/banana.png",
        ":/images/assets/cherry.png",
        ":/images/assets/pear.png"
    };

    // drew the fruit
    setPixmap(QPixmap(fruits[random_fruit]));
    setScale(0.4);


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Fruit::move(){
    setPos(x(),y()+5);


    if (pos().y() > 600)
    {
        //decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }


    // if bucket collides with fruit, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            // remove them both

            game->score->increase();
            scene()->removeItem(this);


            // delete them both
            delete this;
            return;
        }
    }
}
