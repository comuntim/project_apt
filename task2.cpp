#define _CRT_SECURE_NO_WARNINGS  // Отключение предупреждений компилятора для небезопасных функций
#include <stdio.h>  // Включение стандартного заголовочного файла для ввода/вывода
#include <stdlib.h>  // Включение стандартного заголовочного файла для работы с памятью и другими функциями
#define SIZE 6  // Определение константы SIZE

int main()  // Главная функция программы
{
  int a[SIZE][SIZE];  // Объявление матрицы связей
  int d[SIZE];  // Объявление массива минимального расстояния
  int v[SIZE];  // Объявление массива посещенных вершин
  int temp, minindex, min;  // Объявление временных переменных
  int begin_index = 0;  // Индекс начальной вершины

  // Инициализация матрицы связей
  for (int i = 0; i < SIZE; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j < SIZE; j++)
    {
      printf("Введите расстояние %d - %d: ", i + 1, j + 1);
      scanf("%d", &temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }

  // Вывод матрицы связей
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }

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

  // Вывод кратчайших расстояний до вершин
  printf("\nКратчайшие расстояния до вершин: \n");
  for (int i = 0; i < SIZE; i++)
    printf("%5d ", d[i]);

  // Восстановление пути
  int ver[SIZE];  // Массив посещенных вершин
  int end = 4;  // Индекс конечной вершины
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

  // Вывод пути
  printf("\nВывод кратчайшего пути\n");
  for (int i = k - 1; i >= 0; i--)
    printf("%3d ", ver[i]);

  getchar();
  getchar();
  return 0;
}
