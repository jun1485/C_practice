#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;

	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (arr[mid] == target)
		{
			printf("목표 발견! 위치는 idx[%d]\n", mid);
			return mid;
		}
		else
		{
			if (arr[mid] < target) first = mid + 1;
			else if (arr[mid] > target) last = mid - 1;
		}
	}
}

int main()
{
	int idx = 0, n, i = 0, k, target;	
	printf("배열의 크기 입력 -> ");
	scanf("%d", &n);
	int* arr;

	arr = (int*)malloc(sizeof(int) * n);

	printf("배열의 정보(수) 입력 -> ");	// 이진 탐색 알고리즘은 배열의 값들이
	for (i = 0; i < n; i++)					    // 정렬되어있다는 전제 하에 가능.
	{
		scanf("%d", &arr[i]);
	}
	printf("찾는 수 입력 -> ");
	scanf("%d", &target);

	binarySearch(arr, i, target);

	free(arr);
}
