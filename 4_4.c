#include <stdio.h>
int main ()
{
	int i=1, a=1, n;
	
	scanf("%d", &n);
	
	for (i=1; i<=(n-1); i++)
	{
		for (a=1; a<=i; a++ ) printf("*");
	printf("\n");
	a=1;
	}
	
	for (a=1; a<=n; a++ ) printf("*");
	printf("\n");
	
		for (i=1; i<=n-1; i++)
	{
		for (a=n-1; a>=i; a-- ) printf("*");
	printf("\n");
	a=n-1;
	}
	
return 0;
}
