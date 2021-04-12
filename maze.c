#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 12

void visual(int [][n], int, int);
void find_position(int [][n], int*, int*);
void move(int a[][n], int *, int *);


int plan[n][n] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main()
{
    srand(time(NULL));
    int x, y, i = 0;
    int *ptrX = &x, *ptrY = &y;
    find_position(plan, ptrX, ptrY);
    system ("clear");
    visual(plan, x, y);
    system ("sleep 1");
    for(int i=0; i<100;i++)
    {
        move(plan, ptrX, ptrY);
        system ("clear");
        visual(plan, x, y);
        system ("sleep 0.3");
    }
    return 0;
}

void visual(int a[][n], int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==x && j==y) printf("&&");
            else if (a[i][j] == 1) printf("**");
            else printf("  ");
        }
        printf("\n");
    }
}

void find_position(int a[][n], int *X, int *Y)
{
    do
    {
        *X = rand()%11 + 1;
        *Y = rand()%11 + 1;
    }
    while(a[*X][*Y]==1);
}

void move(int a[][n], int *X, int *Y)
{
    char step = getchar();
    switch (step)
    {
    case 's':
        if(a[(*X)+1][*Y]!=1)(*X)++;
        break;
    case 'w':
        if(a[(*X)-1][*Y]!=1)(*X)--;
        break;
    case 'd':
        if(a[*X][(*Y)+1]!=1)(*Y)++;
        break;
    case 'a':
        if(a[*X][(*Y)-1]!=1)(*Y)--;
        break;
    }
}