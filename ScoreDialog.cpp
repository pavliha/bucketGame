#include "ScoreDialog.h"
#include "ui_ScoreDialog.h"
#include "DatabaseScore.h"
#include <QDebug>
#include "Game.h"
#include <QString>

extern Game * game;

ScoreDialog::ScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreDialog)
{
    ui->setupUi(this);
    ui->label_2->setText( QString::number(game->score->getScore()));
}

ScoreDialog::~ScoreDialog()
{
    delete ui;
}

void ScoreDialog::on_pushButton_clicked()
{
    qDebug() << "show database score dialog";
   DatabaseScore * databaseScore = new DatabaseScore;
    //this->close();
    databaseScore->show();

}
