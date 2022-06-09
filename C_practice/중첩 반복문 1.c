#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;	// 1부터 n까지, 1부터 m까지 숫자가 적힌
				// 서로 다른 주사위 2개
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d %d\n", i, j);
		}
	}
}
