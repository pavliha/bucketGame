#ifndef DATABASESCORE_H
#define DATABASESCORE_H

#include <QDialog>

namespace Ui {
class DatabaseScore;
}

class DatabaseScore : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseScore(QWidget *parent = 0);
    ~DatabaseScore();

private slots:
    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::DatabaseScore *ui;
};

#endif // DATABASESCORE_H
