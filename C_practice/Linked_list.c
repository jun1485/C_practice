#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) {int t=a; a=b; b=t;}
#define SIZE 20

typedef struct node {
    int data;
    struct node* next;
}NODE;
