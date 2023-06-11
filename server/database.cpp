/*#include "database.h"


DataBase * DataBase::p_instance;
DataBaseDestroyer DataBase::destroyer; */

#include "database.h"

DataBase* DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;

DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Data.db");

    if (!db.open())
        qDebug() << db.lastError().text();

    QString createTableQuery = "CREATE TABLE IF NOT EXISTS data ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "login VARCHAR(50) NOT NULL, "
                               "pass VARCHAR(50) NOT NULL, "
                               "mail VARCHAR(50) NOT NULL, "
                               "stat VARCHAR(50) NOT NULL DEFAULT '000'"
                               ");";
    QSqlQuery query(db);
    query.exec(createTableQuery);
}

DataBase::~DataBase()
{
    db.close();
}

DataBase* DataBase::getInstance()
{
    if (!p_instance)
    {
        p_instance = new DataBase();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

QString DataBase::sendQuery(const QString& queryStr)
{
    QSqlQuery query(db);

    if (!query.exec(queryStr))
        return query.lastError().text();

    QString res = "";
    int cols = query.record().count();

    while (query.next())
    {
        for (int i = 0; i < cols; i += 1)
            res.append(query.value(i).toString()).append(" ");
    }

    return res;
}
