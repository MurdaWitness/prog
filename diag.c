#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 4

void fill_2d(int[][SIZE], int);
void show_2d(int[][SIZE], int);
void diag(int[][SIZE], int);

int main()
{
    int A[SIZE][SIZE];
    fill_2d(A, SIZE);
    show_2d(A, SIZE);
    printf("\n");
    diag(A, SIZE);
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


void diag(int A[][SIZE], int S)
{
    int itmp;
    int k = S-1;
    for (int i = S-1; i > 0; i--)
    {
        itmp=i;
        for (int j = 0; j < S-k; j++)
        {
            printf("A[%d][%d] = %d\n", itmp+1, j+1, A[itmp][j]);
            itmp++;
        }
        k--;
        printf("\n");
    }


    for (int i = 0; i < S; i++)
    printf("A[%d][%d] = %d\n", i+1, i+1, A[i][i]);
    printf("\n");
    

    int jtmp;
    k = 1;
    for (int j = 1; j < S; j++)
    {
        jtmp=j;
        for (int i = 0; i < S-k; i++)
        {
            printf("A[%d][%d] = %d\n", i+1, jtmp+1, A[i][jtmp]);
            jtmp++;
        }
        k++;
        printf("\n");
    }
}
