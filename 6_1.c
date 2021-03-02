#include <stdio.h>
#include <stdlib.h>
int main()
{
int A[100];
int i;
for(i=1;i<=100;i++)
{
	A[i-1]=i;
	printf("%d ",A[i-1]);
}
return 0;
}