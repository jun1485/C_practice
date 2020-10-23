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

NODE* addNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void transLinkedlist(int* arr, NODE* node) {
    NODE* temp;
    int i;

    for (i = 0, temp = node; i < SIZE; i++) {
        temp->next = addNode(arr[i]);
        temp = temp->next;
    }
}

void print(NODE* node) {
    NODE* printNode = node;

    while (printNode != NULL) {
        printf("%d ", printNode->data);
        printNode = printNode->next;
    }
    printf("\n");
}

NODE* mergeSort(NODE* a, NODE* b) {
    NODE* res = NULL;

    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }
