#include <stdio.h>
int invers(int);

int main()
{
	int a;
	scanf("%d", &a);
	return invers (a);
}

int invers(int a)
{
	int b=0;
	while (a!=0)
	{
		b+=a%10;
		b*=10;
		a/=10;
	{
	return b;
}