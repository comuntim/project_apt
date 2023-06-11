#include <QtTest>
#include "../server/functions.cpp"
// add necessary includes here

class task2test : public QObject
{
    Q_OBJECT

public:
    task2test();
    ~task2test();

private slots:
    void test_case1();

};

task2test::task2test()
{

}

task2test::~task2test()
{

}

void task2test::test_case1()
{
    QString user_answer = "1365"; // правильный ответ

    QVERIFY(task_number_2(0, 4)==user_answer);
}

QTEST_APPLESS_MAIN(task2test)

#include "tst_task2test.moc"
