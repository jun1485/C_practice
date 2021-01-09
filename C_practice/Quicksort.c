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
