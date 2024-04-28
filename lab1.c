#include <stdio.h>
#include <malloc.h>
#include "matr.h"


int main() {
	Matrix matr = {0, NULL}; // исходный массив
	Line result = {0, NULL}; // результирующий вектор суммы в строках
	
	if (input(&matr) == 0) { // ввод матрицы
		printf("%s\n", "End of file occured");
		return 1;
	}

	int r = vect_of_sum(&matr, &result); // вычисление вектора сумм
	output("Source matrix", &matr); // вывод матрицы

	
//вывод вектора сумм b:

	int n = result.n;
	int *ptr = result.a; // указатель на элемент массива
	
	printf("Vector of elments sum b:\n");
	for (int i = 0; i < n; ++i,++ptr)
		printf("%d ", *ptr); // вывод адресов указателя с увеличением его на 1


// освобождение памяти:

	erase(&matr);
	free(result.a);
	return 0;
}
