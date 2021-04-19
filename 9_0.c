#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int a;
FILE *f1;

f1 = fopen("9_0.txt", "w");
for (int i = 0; i < 10; i++)
{
    fprintf(f1, "%d\n", i);
}
fclose(f1);

f1 = fopen("9_0.txt", "r");
for (int i = 0; i < 10; i++)
{
    fscanf(f1, "%d", &a);
    printf("%d ", a);
}
fclose(f1);
return 0;
}