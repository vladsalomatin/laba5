#define _CRT_SECURE_NO_WARNINGS
#define _CTR_NONSTDC_NO_WARNINGS
#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<random>
#include<malloc.h>
#include<locale>

int main()
{
	int **mat;
	int **rez;
	int m, k = 0;
	setlocale(LC_ALL, "Rus");
	printf("Размер матрицы:");
	scanf_s(" %d", &m);

	mat = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		mat[i] = (int*)malloc(m * sizeof(int));
	}
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				mat[i][j] = 0;
			}
			if (i > j) {
				mat[i][j] = rand() % 2;
				if (mat[i][j] == 0)
					mat[i][j] = mat[i][j];
				else
					mat[i][j] = 1 + rand() % 30;
			}
			mat[j][i] = mat[i][j];
		}
	}
	for (int i = 0; i < m; i++) { //VIVOD
		for (int j = 0; j < m; j++) {
			printf(" %4d", mat[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) { //SIZE
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0) {
				k += 1;
			}
		}
	}
	k = k / 2;
	printf("Размер графа: %d", k);
	printf("\n");
	for (int i = 0; i < m; i++) {
		int iz = 0;
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0) {
				iz += 1;
			}
		}
		if (iz == 0)
			printf("\n Вершина %d является изолированной", i + 1);
		else
			printf("\n Вершина %d не является изолированной", i + 1);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		int kon = 0;
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0) {
				kon += 1;
			}
		}
		if (kon == 1)
			printf("\n Вершина %d является концевой", i + 1);
		else
			printf("\n Вершина %d не является концевой", i + 1);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		int dm = 0;
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0) {
				dm += 1;
			}
		}
		if (dm == m - 1)
			printf("\n Вершина %d является доминирующей", i + 1);
		else
			printf("\n Вершина %d не является доминирующей", i + 1);
	}
	printf("\n");


	rez = (int**)malloc(k * sizeof(int*));
	for (int i = 0; i < k; i++) {
		rez[i] = (int*)malloc(m * sizeof(int));
		
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			rez[i][j] = 0;
		}
	}
	int n = 0;
	for (int i = 0; i < m; i++) {
		
		for (int j = i; j < m; j++) {
			if (mat[i][j] != 0) {
				rez[n][i] = rez[n][j] = mat[i][j];
				n++;
			}
		
		}
	}
	
	for (int i = 0; i < k; i++) { //VIVOD
		for (int j = 0; j < m; j++) {
			printf(" %4d", rez[i][j]);
		}
		printf("\n");
	}
	printf("Razmer grafa: %d", k);
	for (int j = 0; j < m; j++) {
		int iz = 0;
		for (int i = 0; i < k; i++) {
			if (rez[i][j] != 0) {
				iz += 1;
			}
		}
		if (iz == 0)
			printf("\n Вершина %d является изолированной", j + 1);
		else
			printf("\n Вершина %d не является изолированной", j + 1);
	}
	printf("\n");
	for (int j = 0; j < m; j++) {
		int kon = 0;
		for (int i = 0; i < k; i++) {
			if (rez[i][j] != 0) {
				kon += 1;
			}
		}
		if (kon == 1)
			printf("\n Вершина %d является концевой", j + 1);
		else
			printf("\n Вершина %d не является концевой", j + 1);
	}
	printf("\n");
	for (int j = 0; j < m; j++) {
		int dm = 0;
		for (int i = 0; i < k; i++) {
			if (rez[i][j] != 0) {
				dm += 1;
			}
		}
		if (dm == m - 1)
			printf("\n Вершина %d является доминирующей", j + 1);
		else
			printf("\n Вершина %d не является доминирующей", j + 1);
	}
	printf("\n");
	getchar();
	getchar();
	return 0;
}
