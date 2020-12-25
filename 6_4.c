#include <stdio.h>
#include <math.h>
#define SIZE 5
int main ()
{
	int A[SIZE] = {1,1,1,1,1};
	for (int i=0; i<SIZE; i++)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
	}
	for (int i=0; i<SIZE; i++) printf("%d ",A[i]);
	printf("\n");
	int last = A[SIZE-1];
	for (int i=SIZE-1; i>=1; i--) A[i] = A[i-1];
	A[0] = last;
	for (int i=0; i<SIZE; i++) printf("%d ",A[i]);
	return 0;
}
