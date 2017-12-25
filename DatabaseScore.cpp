#include "DatabaseScore.h"
#include "ui_DatabaseScore.h"
#include "Database.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

DatabaseScore::DatabaseScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseScore)
{


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("/home/pavel/Code/bucketGame/database.sqlite");

       if (!db.open())
          qDebug() << "Error: connection with database fail";
       else
          qDebug() << "Database: connection ok";

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * query = new QSqlQuery(db);

    query->prepare("SELECT score FROM score ORDER BY id");
    query->exec();
    model->setQuery(*query);


    ui->tableView->setModel(model);

    ui->setupUi(this);
}

DatabaseScore::~DatabaseScore()
{
    delete ui;
}

void DatabaseScore::on_tableView_activated(const QModelIndex &index)
{

}
