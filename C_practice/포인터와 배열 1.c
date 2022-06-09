#include <stdio.h>

int main()
{
	int aList[5] = { 40,20,50,30,10 };
	int nTotal = 0;

	for (int i = 0; i < 5; i++)
	{
		nTotal += aList[i];
	}
	printf("%d\n", nTotal);

	nTotal = 0;
	int* pnData = aList;
	while (pnData < aList + 5)
	{
		nTotal += *pnData;
		pnData++;
	}
	printf("%d\n", nTotal);
}
