#include <stdio.h>
int main()
{
	int n, square=0;
	printf("N = "); scanf("%d",&n);
	for(int i=1; i<=2*n-1; i+=2) square+=i;
	printf("N^2 = %d", square);
	return 0;
}