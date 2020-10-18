#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array[20] = { 0 };
	int temp = 0;

	for (int i = 0; i < 20; i++)
	{
		array[i] = rand() % 1000 + 1;
		printf("%d ", array[i]);
	}
