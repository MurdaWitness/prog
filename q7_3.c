#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main ()
{
    float numbers [SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    float *nPtr = numbers;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%3.1f", numbers [i]);
    }
    printf("\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%3.1f",*(nPtr + i));
    }
    printf("\n");
    printf("%3.1f\n", numbers [3]);
    printf("%3.1f\n", *(numbers + 3));
    printf("%3.1f\n", nPtr[3]);
    printf("%3.1f\n", *(nPtr + 3));
    return 0;
}