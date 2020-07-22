#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* arr;
	int n;

	printf("배열의 크기 -> ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	printf("%d개의 수 입력 -> ", n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) printf("%d ", &arr[i]);
}
