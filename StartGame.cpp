#include "StartGame.h"
#include "ui_StartGame.h"
#include <Game.h>
extern Game * game;

StartGame::StartGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_pushButton_clicked()
{
  game = new Game(this);

  this->close();
}
