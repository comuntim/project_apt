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
class Singleton; //чтоб не ставить потом Singleton::

//переменная p_instance используется для хранения единственного экземпляра класса
//пересенная destroyer - для удаления этого экземпляра при завершении программы

class SingletonDestroyer
{
    private:
        Singleton * p_instance;
    public:
        ~SingletonDestroyer() { delete p_instance;}
        void initialize(Singleton * p){p_instance = p;};
};


class Singleton
{
    private:
        //переменная static существует в единтсвенном экземпляре на весь класс
        static Singleton * p_instance; //* хранит адрес объекта (указатель на объект этого класса)
        static SingletonDestroyer destroyer; //одна из причин отсутствия * это то, что SingletonDestroyer был объявлен до
        //database db
    protected:
        Singleton(){
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("/root/singleton/mydatabase.db");

            if (!db.open()) {
                qDebug() << "Failed to open database!";
            }

            //db open
            //я так понимаю тут тот код для бд должен быть
        }


        Singleton(const Singleton&); //конструктор копирования (копирует все экземпляры класса)
        //делает запрет на создание новых экземпляров класса путем копирования существующего экземпляра
        Singleton& operator = (Singleton &); //оператор присваивания; копия объектов класса самих в себя (прям пониятия не имею зачем эта срока)
        //также делает запрет на создание новых экземпляров класса путем присваивания существующего экземпляра
        //короче говоря те 2 строки гарантируют, что singleton в одном экземпляре, как и его объекты класса
        ~Singleton() { //деструктор singleton
            //db.close();
            //закрытие
        }
        friend class SingletonDestroyer; //означает, что класс SingletonDestroyer будет иметь доступ к private и protected класса Singleton
    public:
        static Singleton* getInstance(){ //метод позволяет получить доступ к единственному экземпляру класса Singleton
            if (!p_instance) //если экземпляр класса еще не создан
            {
                p_instance = new Singleton();
                destroyer.initialize(p_instance); //инициализирует desroyer, чтобы singleton был нормально удален
            }
            return p_instance;
        }


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
