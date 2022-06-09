#include <stdio.h>

int main()
{
	int s, t, sum = 0;
	printf("첫 번째 정수 입력 -> ");
	scanf_s("%d", &s);
	printf("두 번째 정수 입력 -> ");
	scanf_s("%d", &t);
	
	for (int i = s; i <= t; i++)
		if (i % 2 == 0 || i % 3 == 0) sum += i;
	printf("두 정수 사이의 2, 3의 배수의 합 -> ");
	printf("%d\n", sum);
	
	int cnt = 0, N_cnt = 0;
	for (int j=s; j <= t; j++)
	{
		if (j % 2 == 0 || j % 3 == 0) cnt++;
		else N_cnt++;
			
	}
	printf("2 or 3의 배수인 것의 개수 -> %d\n", cnt);
	printf("2 or 3의 배수가 아닌 것의 개수 -> %d\n", N_cnt);
}
