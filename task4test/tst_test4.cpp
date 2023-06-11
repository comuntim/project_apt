#include <QtTest>
#include "../server/functions.cpp"
// add necessary includes here

class test4 : public QObject
{
    Q_OBJECT

public:
    test4();
    ~test4();

private slots:
    void test_case1();

};

test4::test4()
{

}

test4::~test4()
{

}

void test4::test_case1()
{
    QString user_answer = "136163242631634736137442437473576136263173474375"; // правильный ответ

    QVERIFY(task_number_4(7)==user_answer);
}

QTEST_APPLESS_MAIN(test4)

#include "tst_test4.moc"
