#include <stdio.h>
#include <math.h>
#include <time.h>
#define SIZE 10
int main ()
{
	int A[SIZE] = {0};
	srand(time(NULL));
	int i;
	for (i = 1; i <= SIZE; i++)
	{
		A[i-1] = rand () %1000; 
		printf("%d: ", A[i-1]);
	}

printf("\n");

	return 0;
}