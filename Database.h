#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
class Database
{
public:
   
    Database();
    
    void addScore();

    QSqlQueryModel * getScore();
    
private:
    QSqlDatabase db;
    QSqlQuery query;
    
};


#endif // DATABASE_H
