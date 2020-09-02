#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int array[] = { 3, 6, 2, 4, 7, 1 };
	int arrayLength = sizeof(array) / sizeof(array[0]);
	
	int min = array[0];
	for (int i = 0; i < arrayLength; i++)
	{
		if(min > array[i])
		{
			min = array[i];
		}
	}
	printf("%d", min);
}
