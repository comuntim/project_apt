#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;
class DataBaseDestroyer
{
    private:
        DataBase * db_pointer;
    public:
        ~DataBaseDestroyer() { delete db_pointer;}
        void initialize(DataBase * p){db_pointer = p;}
};


class DataBase
{
    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;
        QSqlDatabase db;
    protected:
        DataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Data.db");

            if(!db.open())
                qDebug()<<p_instance->db.lastError().text();

            QString createTableQuery = "CREATE TABLE IF NOT EXISTS data ("
                                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                            "login VARCHAR(50) NOT NULL, "
                                            "pass VARCHAR(50) NOT NULL"
                                            ");";
            QSqlQuery query(db);
            query.exec(createTableQuery);
        }
        DataBase(const DataBase& ) = delete;
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {db.close();}

        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();

                destroyer.initialize(p_instance);

            }
            return p_instance;
        }
        // далее функция для коннекта с бд
        QString sendQuerry(QString str) {
            QSqlQuery query(db);
            query.exec(str);

            if (!query.exec())
                return query.lastError().text();
            return QString();
        }

};


#endif // DATABASE_H