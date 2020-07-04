#include <stdio.h>


int main() {
	int x = 10;
	int i;
	for (i = 0; i < x; i++)
	{
		if (i % 2 == 1) printf("%d", i);
	}
}