#include <stdio.h>
#include <malloc.h>


#define MEMALLOC_ERROR 1
#define OK 0
#define EOF_ERROR 2
#define MATRIX_INPUT_ERROR 3


typedef struct Line {

	int n; // количество элементов в строке матрицы
	int *a; // массив элементов

} Line;

// структура для задания самой матрицы
typedef struct Matrix {

	int lines; // количество строк матрицы
	Line *matr; // массив строк матрицы

} Matrix;


int getInt(int *); // ввод целого числа
int input(Matrix *a); // ввод матрицы
void output(const char *msg, const Matrix *a); // вывод матрицы
void erase(Matrix *a); // освобождение занятой памяти
int line_sum(const Line *line); // вычисление суммы элементов в строке
int vect_of_sum(const Matrix *matrix, Line *result); // вычисление вектора из сумм элементов каждой строки матрицы
