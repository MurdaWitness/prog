#include <stdio.h>
int main ()
{
	int a=1, n;
	printf("Введите число: "); scanf("%d", &n);
	for(int c=1; c<=n; a*=c, c++);
	printf("Факториал числа %d = %d ", n, a);
return 0;
}
