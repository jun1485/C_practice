#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 60000
#define MAX_ELEMENT 60000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType; 

element a[MAX_SIZE];
int sorted[MAX_SIZE];   // 합병 정렬에서 추가 공간이 필요
double start, finish; //시간을 재기위한 변수
int quick_Sort[MAX_SIZE];

int partition(int list[], int left, int right);                //퀵 정렬 
void quick_sort(int list[], int left, int right);              //퀵 정렬 
int n;

void sort_clock();                                          
 
int main()
{

	int i;
	int a = 1;

	printf("데이터의 개수를 입력 하시오 : ");
	scanf("%d", &n);

		

	printf("-----------최선------------\n");
	for (i = 0; i < n; i++) { 
		quick_Sort[i] = a; 
	}

	sort_clock();

	printf("-----------최악------------\n");
	for (i = 0; i < n; i++) { 
		quick_Sort[i] = a;
	}

	sort_clock();

	system("PAUSE");
}

		//퀵 정렬
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

		//정렬들의 실행 시간
void sort_clock()
{
	start = clock();
