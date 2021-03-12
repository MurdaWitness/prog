#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 3

void fill(int [], int);
void show(int[], int);
void convert_matrix(int [], int [][NUM], int);
void show_2d(int [][NUM], int);

int main()
{
    int NQ = NUM*NUM;
    int A[NQ], B[NUM][NUM];
    fill(A,NQ);
    show(A,NQ);
    printf("\n");
    convert_matrix(A, B, NUM);
    show_2d(B, NUM);
    return 0;
}


void fill(int A[], int N)
{
	srand(time(NULL));
	for (int i=0; i<N; i++)
	A[i] = rand()%99 + 1;
}


void show(int A[], int N)
{
	for (int i=0; i<N; i++)
	printf("%-2d\t", A[i]);
	printf("\n");
}


void convert_matrix(int A[], int B[][NUM], int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = A[k];
            k++;
        }
    }
}


void show_2d(int B[][NUM], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%-2d\t", B[i][j]);
        }
        printf("\n");
    }
}