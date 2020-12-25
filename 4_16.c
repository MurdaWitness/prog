#include <stdio.h>
void main()
{
	long int n, f1=1, f2=1, f3;
	printf("Введите n: "); scanf("%ld",&n);
	printf("Последовательность Фибоначчи до n-ого члена:\n");
	if (n == 1) printf("%ld ",f1);
	else if (n == 2) printf("%ld \n%ld ",f1,f2);
	else
	{
		printf("%ld \n%ld ",f1,f2);
		for (int i = 1; i < n-1; i++) 
		{
			f3 = f1 + f2;
			printf("\n%ld ",f3);
			f1=f2;
			f2=f3;
		}
	}
}