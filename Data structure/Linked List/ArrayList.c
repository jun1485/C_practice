#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData > LIST_LEN)
	{
		printf("저장 불가 ! -자료 수 초과-\n");
		return;
	}
	plist->arr[++plist->numOfData] = data;
}
