#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 5

void fill_2d(int[][SIZE], int);
void show_2d(int[][SIZE], int);
void summa(int[][SIZE], int);

int main()
{
    int A[SIZE][SIZE];
    fill_2d(A, SIZE);
    show_2d(A, SIZE);
    printf("\n");
    summa(A, SIZE);
    return 0;
}


void fill_2d(int A[][SIZE], int S)
{
    srand(time(NULL));
    for (int i = 0; i < S; i++) 
    {
        for (int j = 0; j < S; j++)
        A[i][j] = rand()%8 + 1;
    }
}


void show_2d(int A[][SIZE], int S)
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            printf("%-2d", A[i][j]);
        }
        printf("\n");
    }
}


void summa(int A[][SIZE], int S)
{
    A[0][0] = S;
}