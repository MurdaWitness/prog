#include <stdio.h>
int main ()
{
	for(int i=41; i<=125; i++)
	{
		printf("%3c %6d  ", i, i);
		if(i%5 == 0) printf("\n");
	}
return 0;
}
