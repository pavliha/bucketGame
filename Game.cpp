#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Fruit.h"
#include "Bomb.h"
#include <QImage>
#include <QBrush>
#include "dialog.h"
#include <QDebug>
#include "Health.h"

Game::Game(QWidget *){


    //this->showDialog();
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    setBackgroundBrush(QBrush(QImage(":images/assets/forest.jpg")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    scene->setStickyFocus(true);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();

    player->setPixmap(QPixmap(":/images/assets/kosholka.png"));
    player->setScale(0.6);
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);



    // spawn enemies
    QTimer * timer = new QTimer();

    QTimer * timer2 = new QTimer();

    timer->stop();
    timer2->stop();

    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawnBomb()));


    timer->start(2000);
    timer2->start(4000);

    show();

}

void Game::showDialog(){

    qDebug() << "show dialog";
    Dialog * dialog = new Dialog;
    this->close();
    dialog->show();

}
