#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void fill(int [], int);
void show(int[], int);
void sort(int [],int);

int main()
{
	int arr[SIZE];
	fill(arr, SIZE);
	show(arr, SIZE);
	printf("\n");
	sort(arr,SIZE);
	show(arr, SIZE);

	return 0;
}


void fill(int X[], int n)
{
	srand(time(NULL));
	for (int i=0; i<n; i++)
	X[i] = rand()%99 + 1;
}


void show(int X[], int n)
{
	for (int i=0; i<n; i++)
	printf("%d\t", X[i]);
	printf("\n");
}


void sort(int X[],int n)
{
	int tmp;
	int tmn;

	for (int i = 0; i<n-1; i++)
	{
		tmp = X[i];
		tmn = i;
		for (int j=i; j<n; j++)
		{
			if(X[j]<tmp)
			{
				tmp = X[j];
				tmn = j;
			}
		}
		X[tmn] = X[i];
		X[i] = tmp;
	}
}