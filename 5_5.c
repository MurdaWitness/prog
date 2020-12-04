#include <stdio.h>
float sin(float, int);

int main()
{
	float x;
	int e;
	printf("Введите x: "); 
	scanf("%d",&x);
	printf("Введите точность: "); 
	scanf("%d",&e);
	printf("Синус от %d равен %d", x, sin(x, e));
}

float sin(float x, int e);
{
	float sin; fl;
	for (int i = 1; i <= e; i++) 
		fact *=i; 
		sin += pow(-1, i)*(pow(x, 2*i+1)/fact);
	return sin;
}