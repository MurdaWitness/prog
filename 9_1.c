#include <stdio.h>

int main()
{
int n, k;
FILE *f;
if((f = fopen("9_1.txt", "w")) == NULL)
printf("ERROR\n");
else
{
    printf("N = "); scanf("%d", &n);
    printf("K = "); scanf("%d", &k);
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                fprintf(f, "*");
            }
            fprintf(f, "\n");
        }
    fclose(f);
}
return 0;
}