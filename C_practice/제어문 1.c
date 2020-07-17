#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, sum = 0, i = 1;
	scanf("%d", &n);

	while (sum <= n)
	{
		sum += i++;
		if (sum >= n)
		{
			printf("%d", i - 1);
			break;
		}
	}
}
