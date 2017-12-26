#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "StartGame.h"

class Game: public QGraphicsView{
public:
    bool closed = false;

    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

public slots:
    void showDialog();

};

#endif // GAME_H
