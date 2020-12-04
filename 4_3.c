#include <stdio.h>
int main ()
{
	int i=1, a=1;
	
	for (i=1; i<=6; i++)
	{
		for (a=1; a<=i; a++ ) printf("*");
	printf("\n");
	a=1;
	}
	
	for (a=1; a<=7; a++ ) printf("*");
	printf("\n");
	a=1;
	
		for (i=1; i<=6; i++)
	{
		for (a=6; a>=i; a-- ) printf("*");
	printf("\n");
	a=6;
	}
	
return 0;
}
