#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func2(int,int,int);
float func3(int,int,int);
float func4(int,int,int);
float (*func[3])(int,int,int) = {func2,func3,func4};
void halvmethod(int,int,int,float);
void secantmethod(int,int,int,float);
void (*methods[2])(int,int,int,float) = {halvmethod,secantmethod};

int main()
{
	int c,d,a,b,mkey,fkey;
	float e;
	printf("Введите параметры c и d\n");
		scanf("%d%d",&c,&d);
	printf("Введите значение eps\n");
		scanf("%f",&e);
	printf("Введите номер функции\n 0 - e^(c*x)-d\n 1 - log2(c*x)-d\n 2 - x^3+c * x^2 + d\n");//Выбор функции
		scanf("%d",&fkey);
	printf("Введите номер метода\n 0 - метод деления пополам\n 1 - метод секущих\n");//Выбор метода
		scanf("%d",&mkey);
	methods[mkey](c,d,fkey,e); //Вызов выбранного метода с функцией
}

float func2(int x,int c,int d)
{
	return exp(c*x)- d;
}
float func3(int x,int c,int d)
{
	return log2(c*x)-d;
}
float func4(int x,int c,int d)
{
	return pow(x,3)+c*pow(x,2)+d;
}
void halvmethod(int c,int d,int fkey,float eps) //Метод деления отрезка пополам
{
	
	float g;
	int a,b,n=0;
	printf("Введите значения отрезка a и b\n");
	scanf("%d%d",&a,&b);
	while(abs(b-a)> eps)
	{
		g=(a+b)/2;
		if(func[fkey](g,c,d)<0) a = g;
		else b = g;
		n++;
	}
	printf("Итоговое значение = %f\n",g);
	printf("Количество итераций = %d\n",n);
}
void secantmethod(int c,int d,int fkey, float eps) //Метод секущих
{
	float xn,xn1;
	int n =0;
	printf("Введите приближенные значения xn и xb\n");
	scanf("%f%f",&xn,&xn1);
	while(abs(xn-xn1)>eps)
	{
		xn1= xn - func[fkey](xn,c,d) * (xn-xn1)/(func[fkey](xn,c,d)-func[fkey](xn1,c,d)); 
		xn= xn1 - func[fkey](xn1,c,d) * (xn1-xn)/(func[fkey](xn1,c,d)-func[fkey](xn,c,d)); 
		n++;
	}
	printf("Итоговое значение = %f\n",xn);
	printf("Количество итераций = %d\n",n);
}
