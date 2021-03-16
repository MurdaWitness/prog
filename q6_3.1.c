#include<stdio.h>
#define n 8
#define m 9
int main()
{
  int Arr[n][m],c=1;
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<m;j++)
    {
        Arr[i][j] = (c % 2 == 0);
        printf("%-2d",Arr[i][j]);
        c++;
    }
    printf("\n");
    if (m%2==0)c++;
  }
  return 0;
}