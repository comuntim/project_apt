#ifndef DATABASE_H
#define DATABASE_H


#include <QSqlDatabase>
#include <QDebug>
#include <QCoreApplication> //библиотека для консоли
#include <QVariant> //потом скажут
#include <QDebug> //вывод в консоль
#include <QSqlDatabase> //для БД
#include <QSqlQuery> //чтобы работать с запросами
#include <QSqlError> //для ошибок
#include <QSqlRecord> //для работы с ОДНОЙ отдельной записью в БД

//Улучшенная реализация
class DataBase; //чтоб не ставить потом Singleton::

//переменная p_instance используется для хранения единственного экземпляра класса
//пересенная destroyer - для удаления этого экземпляра при завершении программы

class DataBaseDestroyer
{
    private:
        DataBase * DataBasePointer; //ссылка на наш объект
    public:
        ~DataBaseDestroyer() { delete DataBasePointer;}
        void initialize(DataBase * p){DataBasePointer = p;}; //присваивает ту ссылку, которая свойство класса к той ссылке, что мы получили арументом
};


class DataBase
{
    private:
        //переменная static существует в единтсвенном экземпляре на весь класс
        static DataBase * p_instance; //* хранит адрес объекта (указатель на объект этого класса); объект, который ссылается на этот объект
        static DataBaseDestroyer destroyer; //объект, который уничтожает этот объект
        //database db
    protected:
        DataBase(){} //конструктор по умолчанию


        DataBase(const DataBase&); //копирующий конструктор(копирует все экземпляры класса)
        //делает запрет на создание новых экземпляров класса путем копирования существующего экземпляра
        DataBase& operator = (DataBase &); //оператор присваивания; копия объектов класса самих в себя (прям пониятия не имею зачем эта срока)
        ~DataBase() {} //деструктор singleton
            //db.close();
            //закрытие
        friend class SingletonDestroyer; //означает, что класс SingletonDestroyer будет иметь доступ к private и protected класса Singleton


    public:

        static DataBase* getInstance(){ //метод позволяет получить доступ к единственному экземпляру класса Singleton
            if (!p_instance) //если экземпляр класса еще не создан
            {
                p_instance = new DataBase();
                destroyer.initialize(p_instance); //инициализирует desroyer, чтобы singleton был нормально удален
            }
            return p_instance;
        }

    /*
        QString send_query(QString query) {
            QSqlQuery q;
            if (!q.exec(query)) {
                qDebug() << "оШШШибка!" << q.lastError().text();
                return QString();
            }

            QString result;
            while (q.next()) {
                QSqlQuery query;
                query.prepare("INSERT INTO User(password, login) VALUES (:password, :login)");
                query.bindValue(":password","2222");
                query.bindValue(":login","user2");

                query.exec();
                // обработка результатов запроса
            }


            return result;
        }
    */



        /* QString send_query(QString) //объявление функции send_query, которая принимает один аргумент типа QString и возвращает объект типа QString
        {
            //query - запрос
        } */
};

/*
Singleton* Singleton::p_instance = 0;
SingletonDestroyer Singleton::destroyer;
Singleton * SingletonDestroyer::p_instance; //эти строки нужны просто для реализации паттерна singleton
*/


#endif // DATABASE_H
