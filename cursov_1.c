#include <stdio.h>
#include <math.h>

float inf(float, float);

void main()
{
	float x, e;
    printf("Введите x в градусах: ");
	scanf("%f", &x);
    printf("Введите точность вычислений: ");
    scanf("%f", &e);
    x *= (M_PI/180);
    if((e<=0)||(x<=0)) printf("ERR0R");
    else printf("Бесконечная сумма равна %f\n", inf(x, e));
    printf("Тангенс равен %f", tan(x));
}

float inf(float x, float e)
{
    float s, s1, temp, i = 1;
	do
	{
		temp = -1*(i / x);
        printf("%f ", temp);
        s1 = pow(temp, -1);
        printf("%f\n", s1);
        s = s1;
        i+=2;
	}
    while((s1-s)>e);
    return s;
}