#include <stdio.h>

int main()
{
	int* numptr1;
	int** numptr2;
	int num = 10;

	numptr1 = &num;
	numptr2 = &numptr1;

	printf("%d\n", **numptr2);
}
