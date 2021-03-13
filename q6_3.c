#include <stdio.h>
#define SIZE1 5
#define SIZE2 7

void chess(int [][SIZE2], int, int);
void show_2d(int [][SIZE2], int, int);

int main()
{
    int A[SIZE1][SIZE2];
    chess(A, SIZE1, SIZE2);
    show_2d(A, SIZE1, SIZE2);
}


void chess(int A[][SIZE2], int S1, int S2)
{
for(int i = 0; i<S1; i+=2)
    {
        for(int j = 0; j<S2; j+=2)
        A[i][j] = 1;
        for(int j = 1; j<S2; j+=2)
        A[i][j] = 0;
    }

for(int i = 1; i<S1; i+=2)
    {
        for(int j = 0; j<S2; j+=2)
        A[i][j] = 0;
        for(int j = 1; j<S2; j+=2)
        A[i][j] = 1;
    }
}


void show_2d(int A[][SIZE2], int S1, int S2)
{
    for (int i = 0; i < S1; i++)
    {
        for (int j = 0; j < S2; j++)
        {
            printf("%-2d", A[i][j]);
        }
        printf("\n");
    }
}
