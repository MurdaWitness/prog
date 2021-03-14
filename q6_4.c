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
        A[i][j] = rand()%99 + 1;
    }
}


void show_2d(int A[][SIZE], int S)
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            printf("%-3d", A[i][j]);
        }
        printf("\n");
    }
}


void summa(int A[][SIZE], int S)
{
    int sum = 0;
    int itmp;
    int k = S-1;
    for (int i = S-1; i > 0; i--)
    {
        itmp=i;
        for (int j = 0; j < S-k; j++)
        {
            sum += A[itmp][j];
            itmp++;
        }
        k--;
        printf("sum = %d", sum);
        sum = 0;
        printf("\n");
    }


    for (int i = 0; i < S; i++)
    sum+=A[i][i];
    printf("sum = %d", sum);
    sum = 0;
    printf("\n");
    

    int jtmp;
    k = 1;
    for (int j = 1; j < S; j++)
    {
        jtmp=j;
        for (int i = 0; i < S-k; i++)
        {
            sum += A[i][jtmp];
            jtmp++;
        }
        k++;
        printf("sum = %d", sum);
        sum = 0;
        printf("\n");
    }
}
