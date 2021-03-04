#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main()
{
    int arr[SIZE];
    srand(time(NULL));
    
    for(int i=0; i<SIZE; i++)
    {
	    arr[i]=rand()%100;
	    printf("%-2d ",arr[i]);
    }
    printf("\n");

    int tmp;
    for (int i = 0; i<SIZE/2; i++)
    {
        tmp=arr[i];
        arr[i]=arr[SIZE-i-1];
        arr[SIZE-i-1]=tmp;
    }

    for(int i=0; i<SIZE; i++)
    {
	    printf("%-2d ",arr[i]);
    }
    printf("\n");
return 0;
}