#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QSqlDatabase>
//#include <QSqlQuery>
#include <QSqlError>
//#include <QSqlRecord>

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
        DataBase(){}
        DataBase(const DataBase& ) = delete;
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {db.close();}

        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();
                p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
                p_instance->db.setDatabaseName("Data.db");

                if(!p_instance->db.open())
                    qDebug()<<p_instance->db.lastError().text();

                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        // далее функция для коннекта с бд
        static QString sendQuerry(QString str) {return "dskjd";}
};

#endif // DATABASE_H
