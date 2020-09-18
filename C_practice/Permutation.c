#include <stdio.h>
#define SWAP(x, y, t) ((x) = (t), (t) = (y), (y) = (x))

void perm(char* list, int i, int n);

void perm(char* list, int i, int n)
{
	int j, temp = 0;
	if (i == n)
	{
		for (j = 0; j <= n; j++)
		{
			printf("%c", list[j]);
		}
		printf("  ");
	}
	else
	{
