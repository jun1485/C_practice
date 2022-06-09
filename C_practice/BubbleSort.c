#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int array[] = { 1, 9, 3, 6, 11 };
	int arrLength = sizeof(array) / sizeof(array[0]), tmp = 0;
	for (int i = 0; i < arrLength-1; i++)
	{
		for (int j = 0; j < arrLength-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
	}
	for (int i = 0; i < arrLength; i++)
	{
		printf("%d ", array[i]);
	}
}
