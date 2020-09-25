#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y))? 0: 1)
#define MAX_TERMS 100 /* 배열 terms의 크기 */

typedef struct {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS];

int avail = 0;

void attach(float cofficient, int exponent) {
	/* 새로운 항을 다항식에 첨가한다. */
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "다항식에 항이 너무 많다.");
		exit(1);
