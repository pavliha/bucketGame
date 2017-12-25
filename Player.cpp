#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Fruit.h"
#include "Bomb.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
   }

void Player::spawn(){
    Fruit * fruit = new Fruit();
    scene()->addItem(fruit);
}

void Player::spawnBomb(){
    Bomb * bomb = new Bomb();
    scene()->addItem(bomb);
}
