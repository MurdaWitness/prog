#include <stdio.h>
int main()
{
int *Ar = NULL, i=0, j;
do {
printf("a[%d]=",i);
Ar = (int*)realloc(Ar,++i*sizeof(int));
scanf("%d",&Ar[i-1]);
printf ("Вы хотите продолжить (y/n)?\n");
getchar();

} while (getchar() == 'y');
for (j=0;j<i;j++) printf ("A[%d]=%d\n",j,Ar[j]);
free(Ar);
return 0;
}