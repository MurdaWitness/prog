#include <stdio.h>
#include <math.h>
#include "f.c"
int main()
{
	float n;
	printf("n = ");
	scanf("%d", &n);
	printf(count(n));
	return 0;
}

