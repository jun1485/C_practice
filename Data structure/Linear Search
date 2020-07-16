#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>

int LSearch(int ar[], int len, int target)		//Linear Search
{
	for (int i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 3,5,2,4,9 };
	int idx = 0;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
	{
		printf("찾지 못함 !\n");
		return 0;
	}
	else printf("index 위치 -> %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
	{
		printf("찾지 못함 !\n");
		return 0;
	}
	else printf("index 위치 -> %d\n", idx);
}
