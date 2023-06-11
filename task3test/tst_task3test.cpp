#include <QtTest>
#include "../server/functions.cpp"

// add necessary includes here

class task3test : public QObject
{
    Q_OBJECT

public:
    task3test();
    ~task3test();

private slots:
    void test_case1();

};

task3test::task3test()
{

}

task3test::~task3test()
{

}

void task3test::test_case1()
{
    QString user_answer = "2 5 4 3 5 1 4 2 3 1 2 "; // правильный ответ

    QVERIFY(task_number_3(5)==user_answer);
}

QTEST_APPLESS_MAIN(task3test)

#include "tst_task3test.moc"
