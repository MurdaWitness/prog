#include <stdio.h>
int main ()
{
    int a=1, c=1, n;
    printf("Введите число: "); scanf("%d", &n);
while (c <= n)
	{
		a*=c;
		c++;
	}
	printf("Факториал числа %d = %d",n ,a);
return 0;
}
