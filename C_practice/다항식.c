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
	}
	terms[avail].coef = cofficient;
	terms[avail++].expon = exponent;
}
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
	/* A(x)와 B(x)를 더하여 D(x)를 생성한다. */
	float cofficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB)
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
		case -1: /* a의 expon이 b의 expon보다 작은 경우 */
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case  0: /* 지수가 같은 경우 */
			cofficient = terms[startA].coef + terms[startB].coef;
			if (cofficient)
				attach(cofficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case  1: /* a의 expon이 b의 expon보다 큰 경우 */
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	/* A(x)의 나머지 항들을 첨가한다. */
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	/* B(x)의 나머지 항들을 첨가한다. */
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1;
}

void single_mul(float cofficient, int exponent, int startA, int finishA, int* startD, int* finishD) {
	*startD = avail;
	for (; startA <= finishA; startA++)
		attach(cofficient * terms[startA].coef, exponent + terms[startA].expon);
	*finishD = avail - 1;
}
void pmul(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
	int start_sub;
	int finish_sub;
	int start_total = 0;
	int finish_total = -1;
	for (; startA <= finishA; startA++) {
		single_mul(terms[startA].coef, terms[startA].expon, startB, finishB, &start_sub, &finish_sub);
		padd(start_sub, finish_sub, start_total, finish_total, &start_total, &finish_total);
	}
	*startD = start_total;
	*finishD = finish_total;
}



int main() {
	float coef;
	int expon;
	int n;
	int startA, finishA, startB, finishB, startAdd, finishAdd, startMul, finishMul;

	startA = avail;
	attach(3, 20);
	attach(-2, 5);
	attach(4, 0);
	finishA = avail - 1;
	printf("Poly. A\n");

	for (int i = startA; i <= finishA; i++)
		printf("    %8.2f %8d\n", terms[i].coef, terms[i].expon);

	printf("Poly. B\n");

	startB = avail;
	attach(1, 4);
	attach(10, 3);
	attach(-3, 2);
	attach(1, 0);
	finishB = avail - 1;

	for (int i = startB; i <= finishB; i++)
		printf("    %8.2f %8d\n", terms[i].coef, terms[i].expon);

	printf("Poly. Addtion\n");

	padd(startA, finishA, startB, finishB, &startAdd, &finishAdd);

	for (int i = startAdd; i <= finishAdd; i++)
		printf("    %8.2f %8d\n", terms[i].coef, terms[i].expon);

	printf("Poly. Multiplication\n");

	pmul(startA, finishA, startB,
