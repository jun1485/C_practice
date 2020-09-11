#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 1000000
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int[], int);
int is_sorted(int list[], int n);
int binsearch(int list[], int low, int high, int target);

int main(void)
{
	int i, n, temp = 0, target;
	int list[MAX_SIZE];
	double result = 0;

	printf("데이터의 개수 : ");
	scanf_s("%d", &n);
	if (n < 1 || n > MAX_SIZE) {
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
	{
		list[i] = i;
	}
	printf("\n");
	clock_t start;
	start = clock();
	sort(list, n);
	result = ((double)(clock() - start)) / CLOCKS_PER_SEC;
	printf("duration = %lf\n", result);
	is_sorted(list, n);

	printf("target을 입력 : ");
	scanf("%d", &target);
	binsearch(list, 0, n, target);
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
			printf("정상적으로 작동하였습니다.\n");
			return 1;
		}
		else
		{
			printf("오류가 발생하였습니다.\n");
			return 0;
		}
	}
}

int binsearch(int list[], int low, int high, int target)
{
	int count = 0, middle = 0;
	while (low <= high)
	{
		count++;
		middle = (low + high) / 2;
		if (middle == target)
		{
			printf("값을 찾음 ! %d번 걸렸음\n", count);
			break;
		}
		else if (middle < target)
		{
			low = middle + 1;
		} 
		else if (middle > target)
		{
			high = middle - 1;
		}
		if (low > high)
		{
			printf("값을 찾을 수 없음 !\n");
			return 0;
		}
	}
}
