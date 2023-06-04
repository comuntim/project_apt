#include <stdio.h>
#include <stdlib.h>
#define SIZE 6


int main()
{
  int a[SIZE][SIZE]; // матрица связей
  int d[SIZE]; // минимальное расстояние
  int v[SIZE]; // посещенные вершины
  int temp, minindex, min;
  int begin_index = 0;
  int start, end; // новые переменные для начальной и конечной точек

  // Инициализация матрицы связей
  for (int i = 0; i<SIZE; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      printf("Введите расстояние %d - %d: ", i + 1, j + 1);
      scanf("%d", &temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }

  // Вывод матрицы связей
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }

  // Ввод начальной и конечной точек
  printf("\nВведите начальную точку: ");
  scanf("%d", &start);
  printf("Введите конечную точку: ");
  scanf("%d", &end);

  //Инициализация вершин и расстояний
  for (int i = 0; i<SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }

  d[start - 1] = 0; // Обновляем начальную точку
  begin_index = start - 1; // Изменяем начальный индекс

  // Шаг алгоритма
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    { // Если вершину ещё не обошли и вес меньше min
      if ((v[i] == 1) && (d[i] < min))
      { // Переприсваиваем значения
        min = d[i];
        minindex = i;
      }
    }

    // Добавляем найденный минимальный вес
    // к текущему весу вершины
    // и сравниваем с текущим минимальным весом вершины
    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
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
  for (int i = 0; i<SIZE; i++)
    printf("%5d ", d[i]);

  // Восстановление пути
  int ver[SIZE]; // массив посещенных вершин
  ver[0] = end; // начальный элемент - конечная вершина
  int k = 1; // индекс предыдущей вершины
  int weight = d[end - 1]; // вес конечной вершины
  int prev; // предыдущая вершина

  while (end != start) // пока не дошли до начальной вершины
  {
    for (int i = 0; i < SIZE; i++) // просматриваем все вершины
    {
      if (a[i][end - 1] != 0)   // если связь есть
      {
        int temp = weight - a[i][end - 1]; // определяем вес пути из предыдущей вершины
        if (temp == d[i]) // если вес совпал с рассчитанным
        {                 // значит из этой вершины и был переход
          weight = temp; // сохраняем новый вес
          prev = i + 1;  // сохраняем предыдущую вершину
          ver[k] = prev; // и записываем ее в массив
          k++;
          end = prev; // обновляем конечную вершину
          break;      // выходим из цикла после нахождения вершины
        }
      }
    }
  }

  // Вывод пути
  printf("\nКратчайший путь от точки %d до точки %d:\n", start, ver[0]);
  for (int i = k - 1; i >= 0; i--)
    printf("%3d ", ver[i]);


  return 0;
}
