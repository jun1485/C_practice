#include <stdio.h>
#define SWAP(x, y, t) ((x) = (t), (t) = (y), (y) = (x))

void perm(char* list, int i, int n);

int main()
{

}

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
		for (j = i; j <= n; j++)
		{
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}
