#include <QtTest>
#include "../server/functions.cpp"
// add necessary includes here

class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void test_case1();

};

test1::test1()
{

}

test1::~test1()
{

}

void test1::test_case1()
{
    QString user_answer = "23"; // правильный ответ

    QVERIFY(task_number_1(4)==user_answer);
}

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
