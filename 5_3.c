#include <stdio.h>
int fib(int);

int main()
{
	int N;
	printf("Введите число: "); 
	scanf("%d",&N);
	printf("Число Фиббоначчи равно %d", fib(N));
}

int fib(int N)
{
	if (N<3) return 1;
	else for(int fi = 2; fi<=N; fi+=fi2)
	return fi2;
}