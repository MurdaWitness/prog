#include <stdio.h>
#include <math.h>
#include <time.h>
#define SIZE 10
int main ()
{
	int A[SIZE] = {0};
	srand(time(NULL));
	int i;
	for (i = 1; i <= SIZE; i++) A[i-1] = rand () % 100;
	for (i = 1; i <= SIZE; i++)
		printf("A[%d] = %-5d\n", i-1, A[i-1]);
	int max = A[0], min = A[0], chet = 0;
	for (i = 0; i<SIZE; i++)
	{
		if (min>A[i]) min = A[i];
		if (min<A[i]) max = A[i];
		if (A[i] % 2 == 0) chet++;
	}
	printf("Максимальный элемент равен: %d\n",max);
	printf("Минимальный элемент равен: %d\n",min);
	printf("Кол-во чётных элементов массива равно: %d\n",chet);
	
	float sr = 0;
	for (i = 0; i<SIZE; i++) sr += A[i];
	sr /= SIZE;
	printf("Среднее значение элементов массива равно: %.3f\n",sr);
	
	float sko = 0;
	for (i = 0; i<SIZE; i++) sko += pow(A[i]-sr,2);
	sko /= SIZE;
	printf("Среднее квадратическое отклонение массива равно: %.3f\n",sko);
	return 0;
}