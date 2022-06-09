#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 1000000
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int[], int);
int is_sorted(int list[], int n);
int main(void)
{
	int i, n, temp = 0;
	int list[MAX_SIZE];
	double result = 0;

	printf("데이터의 개수 : ");
	scanf_s("%d", &n);
	if (n < 1 || n > MAX_SIZE) {
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < n; i++) {
		list[i] = rand() % 100001;
		printf("%d ", list[i]);
	}
	printf("\n");
	for (int i = 0; i < n - 1; i++)//역순정렬
	{
		for (int j = i + 1; j < n; j++)
		{
			if (list[i] < list[j])
			{
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}
	printf("역순정렬\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	clock_t start;
	start = clock();
	sort(list, n);
	result = ((double)(clock() - start)) / CLOCKS_PER_SEC;
	printf("duration = %lf\n", result);
	is_sorted(list, n);


}

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}

}

int is_sorted(int list[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (list[i] <= list[i + 1])
		{
			printf("정상적으로 작동하였습니다.");
			return 1;
		}
		else
		{
			printf("오류가 발생하였습니다.");
			return 0;
		}
	}
}
