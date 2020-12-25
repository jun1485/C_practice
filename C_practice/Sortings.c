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
int sorted[MAX_SIZE];  
double start, finish; 
int selection_Sort[MAX_SIZE]; //선택 
int insertion_Sort[MAX_SIZE]; //삽입 
int merge_Sort[MAX_SIZE]; //합병 
int heap_Sort[MAX_SIZE]; //히프 
int n;


void selection_sort(int list[], int n);                        //선택 정렬
void insertion_sort(int list[], int n);                       //삽입 정렬 
void merge(int list[], int left, int mid, int right);          //합병 정렬 
void merge_sort(int list[], int left, int right);          
void heap_sort(element a[], int n);                            //히프 정렬 
void insert_max_heap(HeapType* h, element item);              
element delete_max_heap(HeapType* h);                      
init(HeapType* h);                                            
void sort_clock();                                           

	int main()
	{

		int i; //반복을 돌리기위해 선언
		int a = 1;

		printf("데이터의 개수를 입력 하시오 : ");
		scanf("%d", &n);

		printf("-----------최선------------\n");
	for (i = 0; i < n; i++) { //최선 
		selection_Sort[i] = a; //선택
		insertion_Sort[i] = a; //삽입
		merge_Sort[i] = a; //합병
		heap_Sort[i] = a++; //히프
	}
	sort_clock();

	printf("-----------최악------------\n");
	for (i = 0; i < n; i++) { //최악 
		selection_Sort[i] = --a;
		insertion_Sort[i] = a;
		merge_Sort[i] = a;
		heap_Sort[i] = a;
	}
	sort_clock();

	system("PAUSE");
}



		//선택 정렬
void selection_sort(int list[], int n)
{

	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// 최소값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
	finish = clock();  // 시간 끝             
}
		//삽입 정렬
void insertion_sort(int list[], int n)
{

	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
		list[j + 1] = key;
	}
}
		//합병 정렬
/* i는 정렬된 왼쪽리스트에 대한 인덱스
   j는 정렬된 오른쪽리스트에 대한 인덱스
   k는 정렬될 리스트에 대한 인덱스 */
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)	/* 남아 있는 레코드의 일괄 복사 */
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else	/* 남아 있는 레코드의 일괄 복사 */
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	/* 배열 sorted[]의 리스트를 배열 list[]로 재복사 */
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
//
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;     /* 리스트의 균등 분할 */
		merge_sort(list, left, mid);    /* 부분 리스트 정렬 */
		merge_sort(list, mid + 1, right); /* 부분 리스트 정렬 */
		merge(list, left, mid, right);    /* 합병 */
	}
}
		//히프 정렬
void insert_max_heap(HeapType* h, element item) //히프 삽입 함수 
{
	int i;
	i = ++(h->heap_size);
