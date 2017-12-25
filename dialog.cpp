#include "dialog.h"
#include "ui_dialog.h"
#include "Game.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>
#include <Database.h>
#include <QString>

extern Game * game;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    ui->label_2->setText(QString::number(game->score->getScore()));

    Database database;

    database.addScore();

    ui->tableView->setModel( database.getScore());
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
//    delete game;

//   new Game;
//     close();

//     delete this;
    delete game;
    this->close();
    new Game;
}
