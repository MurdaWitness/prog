#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int n;
int *testArr;
srand(time(NULL));

FILE *f = fopen("9_3.txt", "w");
printf("N = "); scanf("%d", &n);
testArr = (int *)calloc(n, sizeof(int));
for (int i = 0; i < n; i++)
{
    fprintf(f, "%d\n", rand()%9 + 1);
}
fclose(f);

f = fopen("9_3.txt", "r");
FILE *fr = fopen("9_3r.txt", "w");
for (int i = 0; i < n; i++)
{
    fscanf(f, "%d", &testArr[i]);
}
for (int i = n-1; i >= 0; i--)
{
    fprintf(fr, "%d\n",testArr[i]);
}

fclose(f);
fclose(fr);
return 0;
}