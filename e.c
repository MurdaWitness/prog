#include <stdio.h>
#include<math.h>
float my_sin(float, float);

int main(){
  float a, e;
  printf("a=");
  scanf("%f",&a);
  printf("e=");
  scanf("%f",&e);
  printf("sin(%f)=%f\n", a, my_sin(a,e));
  printf("реальное значение sin(%f)=%f\n", a, sin(a));
  return 0;
}

float my_sin(float a,float e){
  float s=0,x=a;
  long int f=1, i=1,c=1;
  register float ss=sin(a);
  while (fabs(s-ss)>e){
    if (i%2==1)
    {
	s+=c*x/f;
	c*=-1;
	printf("%f\n",s);
	}
		x*=x;
		f*=(++i);
	}
  return s;
}