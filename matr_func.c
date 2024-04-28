#include <stdio.h>
#include <malloc.h>
#include "matr.h"


int getInt(int *a) {
	int n;
	
	do{
		n = scanf("%d", a);
		if (n < 0)
			return OK;
		if (n == 0) {
			printf("%s\n", "Error! Repeat input");
			scanf("%*c");
		}
	} while (n == 0);
	
	return EOF_ERROR;
}


int input(Matrix *rm) {
	const char *pr = "";
	int m, i, j, *p;
	
	do{
		printf("%s\n", pr);
		printf("Enter number of lines: --> ");
		pr = "You are wrong; repeat, please!";
		if (getInt(&m) == OK)
			return OK;
	} while (m < 1);
	
	rm->lines = m;
	rm->matr = (Line *)calloc(m, sizeof(Line));
	
	for (i = 0; i < rm->lines; ++i) {
		pr = "";
		
		do{
			printf("%s\n", pr);
			printf("Enter number of items in line %d: --> ", i + 1);
			pr = "You are wrong; repeat, please!";
			if (getInt(&m) == OK) {
				rm->lines = i;
				erase(rm);
				return OK;
			}
		} while (m < 1);
		
		rm->matr[i].n = m;
		
		p = (int *)malloc(sizeof(double) * m);
		if (!p)
			return MEMALLOC_ERROR;
			
		rm->matr[i].a = p;
		printf("Enter items for matrix line #%d:\n", i + 1);
		
		for (j = 0; j < m; ++j, ++p) {
			if (getInt(p) == OK) {
				rm->lines = i + 1;
				erase(rm);
				return OK;
			}
		}
	}
	return MATRIX_INPUT_ERROR;
}


void output(const char *msg, const Matrix* matrix) {
	int i, j;
	int *p;
	printf("%s:\n", msg);
	
	for (i = 0; i < matrix->lines; ++i) {
		p = matrix->matr[i].a;
		
		for (j = 0; j < matrix->matr[i].n; ++j, ++p)
			printf("%d ", *p);
			
		printf("\n");
	}
}


void erase(Matrix *a) {
	int i;
	
	for (i = 0; i < a->lines; ++i)
		free(a->matr[i].a);
		
	free(a->matr);
	a->lines = 0;
	a->matr = NULL;
}


int line_sum(const Line *line) {
	int n = line->n;
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += line->a[i];

	return sum;
}


int vect_of_sum(const Matrix *matrix, Line* result) {
	int m = matrix->lines;
	int *arr = (int *)malloc(sizeof(int) * m); // декларируем массив сумм
	if (!arr)
		return MEMALLOC_ERROR;
	
	for (int i = 0; i < m; i ++)
		arr[i] = line_sum(&matrix->matr[i]); // заполняем массив сумм


	result->a = arr;
	result->n = m;
	return OK;
}

