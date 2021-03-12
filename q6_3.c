#include <stdio.h>
#define SIZE 5

void show_2d(int [][SIZE], int);

int main()
{
    int A[SIZE][SIZE];
    for(int i = 0; i<SIZE; i+=2)
    {
        for(int j = 0; j<SIZE; j+=2) 
        A[i][j] = 1;
        for(int j = 1; j<SIZE; j+=2) 
        A[i][j] = 0;
    }

    for(int i = 1; i<SIZE; i+=2)
    {
        for(int j = 0; j<SIZE; j+=2) 
        A[i][j] = 0;
        for(int j = 1; j<SIZE; j+=2) 
        A[i][j] = 1;
    }

    show_2d(A, SIZE);    
}


void show_2d(int A[][SIZE], int S)
{
    for (int y = 0; y < S; y++)
    {
        for (int k = 0; k < S; k++)
        {
            printf("%-2d", A[y][k]);
        }
        printf("\n");
    }
}