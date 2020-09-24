#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y))? 0: 1)
#define MAX_TERMS 100 /* 배열 terms의 크기 */

typedef struct {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS];
