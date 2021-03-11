#include "choice.h"
#define SIZE 10

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