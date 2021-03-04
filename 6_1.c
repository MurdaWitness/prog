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
    for(int i=0; i<SIZE-1; i++)
        for(int j=0; j<SIZE-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    
    
    for(int i=0; i<SIZE; i++)
    {
	    printf("%-2d ",arr[i]);
    }
    printf("\n");
    return 0;
}