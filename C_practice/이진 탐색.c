#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int array[40], target, i = 0, res = 0;
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		array[i] = i * 10;
	}
	scanf("%d", &target);
	int first = 0, last = 40-1, middle = (first+last)/2;
	while (first <= last)
	{
		if (array[middle] < target)
		{
			first = middle + 1;
		}
		else if (array[middle] == target)
		{
			printf("%d번째에 있음 !", middle);
			return 0;
		}
		else
		{
			last = middle - 1;
		}
		middle = (first + last) / 2;
	}
	if (first > last)
		printf("찾지 못함 ! ");

	return 0;
}
