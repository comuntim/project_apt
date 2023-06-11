#include "functions.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

QString parsing(QString inputString){
    /* InputString = "NameOfFunc&Arg1&arg2"
       хотим возвратить NameOfFunc (Arg1, arg2);
    */

    qDebug() << inputString;
    QStringList inputString_list = inputString.split('&');
    qDebug() << inputString_list;
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front(); //удаляет имя функции из списка NameOfFunc


    if (NameOfFunc == "auth")
        return auth(inputString_list.at(0), inputString_list.at(1));
    if (NameOfFunc == "reg")
        return reg(inputString_list.at(0), inputString_list.at(1), inputString_list.at(2));
    if (NameOfFunc == "updstat")
        return updstat(inputString_list.at(0), inputString_list.at(1), inputString_list.at(2));
    if (NameOfFunc == "stat")
        return statisticBd(inputString_list.at(0));

    return 0;


}


QString auth(QString log, QString pass){
    QString query =
            QString("SELECT * FROM data WHERE login='%1' AND pass='%2'").arg(log).arg(pass);

    QString result = DataBase::getInstance()->sendQuery(query);
    qDebug() << result;
    if (result.isEmpty()){
        qDebug() << "you are not welcome. Run away!";
        return "auth&-&error";}
    else{
        qDebug() << "you are welcome";
        return "auth&+&"+log;}
}


QString reg(QString log, QString pass, QString mail){
    QString querry =
            QString("INSERT INTO data (login, pass, mail) VALUES ('%1', '%2', '%3');").arg(log).arg(pass).arg(mail);

    QString result = DataBase::getInstance()->sendQuery(querry);
    qDebug() << result;
    if (result.isEmpty())
        return "registration";
    else
        return "error";
}


QString updstat(QString log, QString n, QString upd){
    qDebug() << log << n << upd;
    QString helpQuerry = QString("SELECT stat FROM data WHERE login='%1'").arg(log);
    QString helpStatistic = DataBase::getInstance() -> sendQuery(helpQuerry);

    int n_int = n.toInt();
    if (upd == "+") {
        helpStatistic.replace(n_int - 1, 1, "1");
        QString querry =
            QString("UPDATE data SET stat = '%1' WHERE login = '%2';").arg(helpStatistic).arg(log);
        QString result = DataBase::getInstance()->sendQuery(querry);
        qDebug() << "result "<< result;
    }
    else if (upd == "-"){
        helpStatistic.replace(n_int - 1, 1, "0");
        QString querry =
            QString("UPDATE data SET stat = '%1' WHERE login = '%2';").arg(helpStatistic).arg(log);
        QString result = DataBase::getInstance()->sendQuery(querry);
    }

    return "hello";
}


QString statisticBd(QString log){
    QString querry =
        QString("SELECT stat FROM data WHERE login = '%1';").arg(log);

    QString result = DataBase::getInstance()->sendQuery(querry);
    return result;
}

QString task_number_2(int beginning, int ending){
    QString answer = "";
    int SIZE = 6;
    int d[SIZE];  // Объявление массива минимального расстояния
    int v[SIZE];  // Объявление массива посещенных вершин
    int temp, minindex, min;  // Объявление временных переменных
    int begin_index = beginning;  // Индекс начальной вершины (в этой случае 1)

    int a[6][6] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };

    // Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;

    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        {
            if ((v[i] == 1) && (d[i] < min))
            {
                min = d[i];
                minindex = i;
            }
        }
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);

    // Восстановление пути
    int ver[SIZE];  // Массив посещенных вершин
    int end = ending;  // Индекс конечной вершины
    ver[0] = end + 1;  // Начальный элемент - конечная вершина
    int k = 1;  // Индекс предыдущей вершины
    int weight = d[end];  // Вес конечной вершины

    while (end != begin_index)  // Пока не дошли до начальной вершины
    {
        for (int i = 0; i < SIZE; i++)  // Просматриваем все вершины
        {
            if (a[i][end] != 0)  // Если связь есть
            {
                int temp = weight - a[i][end];  // Определяем вес пути из предыдущей вершины
                if (temp == d[i])  // Если вес совпал с рассчитанным
                {
                    weight = temp;
                    end = i;
                    ver[k] = i + 1;
                    k++;
                }
            }
        }
    }
    for (int i = k - 1; i >= 0; i--)
        answer += QString::fromStdString(std::to_string(ver[i]));

    return answer;
}

void push(Node*& st, int dat)
{
    Node* el = new Node;
    el->inf = dat;
    el->next = st;
    st = el;
}

int pop(Node*& st)
{
    int value = st->inf;
    Node* temp = st;
    st = st->next;
    delete temp;

    return value;
}

int peek(Node* st)
{
    return st->inf;
}

Node** graph; // Массив списков смежности
const int vertex = 1; // Первая вершина

void add(Node*& list, int data)
{
    if (!list)
    {
        list = new Node;
        list->inf = data;
        list->next = 0;
        return;
    }

    Node* temp = list;
    while (temp->next)
        temp = temp->next;
    Node* elem = new Node;
    elem->inf = data;
    elem->next = NULL;
    temp->next = elem;
}

void del(Node*& l, int key)
{
    if (l->inf == key)
    {
        Node* tmp = l;
        l = l->next;
        delete tmp;
    }
    else
    {
        Node* tmp = l;
        while (tmp)
        {
            if (tmp->next && tmp->next->inf == key)
            {
                Node* tmp2 = tmp->next;
                tmp->next = tmp->next->next;
                delete tmp2;
            }
            tmp = tmp->next;
        }
    }
}

int eiler(Node** gr, int num)
{
    int count;
    for (int i = 0; i < num; i++)
    {
        count = 0;
        Node* tmp = gr[i];

        while (tmp)
        {
            count++;
            tmp = tmp->next;
        }
        if (count % 2 == 1)
            return 0;
    }
    return 1;
}

void eiler_path(Node** gr, QString& cycle)
{
    Node* S = NULL;
    int v = vertex;
    int u;

    push(S, v);
    while (S)
    {
        v = peek(S);
        if (!gr[v])
        {
            v = pop(S);
            cycle += QString::number(v + 1) + " ";
        }
        else
        {
            u = gr[v]->inf;
            push(S, u);
            del(gr[v], u);
            del(gr[u], v);
        }
    }
}
QString task_number_3(int termin){
    int n = termin; // Количество вершин
    int graphData[5][5] = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    graph = new Node*[n];
    for (int i = 0; i < n; i++)
        graph[i] = NULL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graphData[i][j])
                add(graph[i], j);

    QString euler_cycle = "";
    if (eiler(graph, n))
        eiler_path(graph, euler_cycle);
    else
        euler_cycle = "Граф не является эйлеровым.";
    qWarning() << euler_cycle;
    return euler_cycle;

}

int printMST(int parent[], int graph[][4], int V) {
    int minCost = 0;
    for (int i = 1; i < V; ++i) {
        minCost += graph[i][parent[i]];
    }
    std::cout << "Наименьший каркас: " << minCost << std::endl;
    return minCost;
}

int findMinKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

QString primMST(int graph[][4], int V) {
    int parent[4];
    int key[4];
    bool mstSet[4];

    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);

    return QString::number(printMST(parent, graph, V));
}

QString task_number_1(int T) {
    int cost[4][4] = {
        {0, 10, 0, 11},
        {10, 0, 9, 5},
        {0, 9, 0, 8},
        {11, 5, 8, 0}
    };
    int V = T;
    QString ret = primMST(cost, V);
    qWarning() << ret;
    return ret;
}
