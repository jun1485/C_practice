#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int array[] = { 1, 9, 3, 6, 11, 15, 12, 13 };
	int arrLength = sizeof(array) / sizeof(array[0]), temp = 0;
	int minValueIdx = 0;

	for (int i = 0; i < arrLength - 1; i++)
	{
		minValueIdx = i;
		for (int j = i+1; j < arrLength; j++)
		{
			if (array[minValueIdx] > array[j])
			{
				minValueIdx = j;
			}
		}
		temp = array[minValueIdx];
		array[minValueIdx] = array[i];
		array[i] = temp;
	}

	for (int k = 0; k < arrLength; k++)
	{
		printf("%d ", array[k]);
	}
}
