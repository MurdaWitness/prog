#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 7

void fill(float [], int);
void show(float[], int);
void minus(float [], int);

int main()
{
    float A[NUM];
    fill(A,NUM);
    show(A,NUM);
    printf("\n");
    minus(A, NUM);
    show(A, NUM);
    return 0;
}


void fill(float A[], int N)
{
	srand(time(NULL));
	for (int i=0; i<N; i++)
	A[i] = rand()%99 + 1;
}


void show(float A[], int N)
{
	for (int i=0; i<N; i++)
	printf("%-6.2f\t", A[i]);
	printf("\n");
}


void minus(float A[], int N)
{
    float sr, sum = 0;
    for (int i = 1; i < N; i++)
    {
        for (int k = 0; k < i; k++)
        {
            sum+=A[k];
        }
        sr = sum/i;
        sum = 0;
        A[i] -= sr;
    }
    
}