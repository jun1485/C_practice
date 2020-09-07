#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 101
#define SWAP(x, y) {int temp; temp=x; x=y; y=temp;}

void sort(int list[], int n);

int main()
{
	int n;
	int list[MAX_SIZE];
	printf("최대 100개의 정렬할 랜덤의 수 입력 : ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 1000;
	}
	
	sort(list, n);
}

void sort(int list[], int n)
{
	int min = 0, k = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (k = i + 1; k < n; k++)
		{
			if (list[min] > list[k])
			{
				min = k;
			}
		}
		SWAP(list[i], list[min]);
	}
	for (int j = 0; j < n; j++)
	{
		printf("%d ", list[j]);
	}
}
