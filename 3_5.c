/*Программа пишет число в обратном порядке. Вводят 123, а программа выводит 321*/
#include <stdio.h>
#include <math.h>

int main()
{
  int a, b = 0, c = 0, z = 0, d, e, f;
  
  scanf("%d",&a);
  e = a; f = a;
  
  while(a != 0)
    {
      a/=10;
      b++;
    }
  
  while(c != b)
    {
      d = e % 10;
      z = z + (d * pow(10,b-c-1)) ;
      e /= 10;
      c++;
    }
  
  (f == z)? printf("Число палиндром\n"): printf("Число не палиндром\n");
  
  return 0;
}
