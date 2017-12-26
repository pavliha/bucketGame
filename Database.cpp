#include "Database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <Game.h>
#include <QDir>
#include <QCoreApplication>
#include <QString>

extern Game * game;

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    QDir dir(QCoreApplication::applicationDirPath());
    QString absolute_file_path = dir.absoluteFilePath("../bucketGame/database.sqlite");


     qDebug() << absolute_file_path;

     db.setDatabaseName(absolute_file_path);

       if (!db.open())
          qDebug() << "Error: connection with database fail";
       else
          qDebug() << "Database: connection ok";
}


void Database::addScore()
{
    QSqlQuery * query = new QSqlQuery(db);

    query->prepare("INSERT INTO score(score) values(:score)");
    query->bindValue(":score", game->score->getScore());

    qDebug()<<query->exec()<<endl;
}

QSqlQueryModel * Database::getScore()
{


    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * query = new QSqlQuery(db);

    query->prepare("SELECT score FROM score ORDER BY id");
    query->exec();
    model->setQuery(*query);

    return model;
}

