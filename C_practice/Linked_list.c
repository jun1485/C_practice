#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) {int t=a; a=b; b=t;}
#define SIZE 20

typedef struct node {
    int data;
    struct node* next;
}NODE;

void randAlloc(int* arr) {
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000 + 1;
}

void selectionSort(int* arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[i] > arr[j]) {
                SWAP(arr[i], arr[j]);
            }
        }
    }
}
