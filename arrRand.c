#include <stdio.h>
#include <math.h>
#include <time.h>
#define SIZE 10
int main ()
{
	int A[SIZE];
    int i;

	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		A[i] = rand()%99 + 1; 
		printf("%d ", A[i]);
	}

printf("\n");

	return 0;
}
