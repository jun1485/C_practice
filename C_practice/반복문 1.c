#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c, day = 1, Dday = 0;  
	scanf("%d %d %d", &a, &b, &c); 

	for (day = 1; Dday == 0; day++)
	{
		Dday = (day % a == 0 && day % b == 0 && day % c == 0);
	}
	printf("%d", day-1);
}
