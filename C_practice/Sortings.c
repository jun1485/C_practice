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
