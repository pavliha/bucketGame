#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>

namespace Ui {
class StartGame;
}

class StartGame : public QDialog
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = 0);
    ~StartGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartGame *ui;
};

#endif // STARTGAME_H
