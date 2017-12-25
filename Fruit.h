#ifndef FRUIT_H
#define FRUIT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Fruit: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    static int lastFruit;
    Fruit(QGraphicsItem * parent=0);

public slots:
    void move();


};



#endif // FRUIT_H
