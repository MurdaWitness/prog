#include <stdio.h>
int main ()
{
	int a=1;
	for(int c=1; c<=15; a*=c, c+=2);
	printf("%d ", a);
return 0;
}
