#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[100] = { 0 };
	int n, k, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		arr[i] = k;
	}
	res = (arr[0] < arr[1]) ? arr[0] : arr[1];
	for (int i = 0; i < n; i++)
	{
		if (res > arr[i]) res = arr[i];
	}
	printf("%d", res);

        return 0;
}
