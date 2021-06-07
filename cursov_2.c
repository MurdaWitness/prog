#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float method_1(int, float, float, float, int *);
float method_2(int, float, float, float, int *);
float equation_2(float, float, float);
float equation_4(float, float, float);
float equation_5(float, float, float);
float derivative_2(float, float, float);
float derivative_4(float, float, float);
float derivative_5(float, float, float);

float (*f[2][6])(float, float, float) = {{equation_2, equation_4, equation_5}, {derivative_2, derivative_4, derivative_5}};
int sign(float);

void main()
{   
    system("clear");
    int f_choice, m_choice, count = 0;
    float c, d, e, x;
    printf("Выберите номер уравнения:\n");
    printf("1: y = e^xc - d\n");
    printf("2: y = x^3 + cx^2 + d\n");
    printf("3: y = x^4 + cx^3 - dx\n");
    do
    {
        printf("\nВведите номер уравнения: ");
        scanf("%d", &f_choice);
        if((f_choice<1)||(f_choice>3)) printf("Ошибка! Уравнение под введённым номером отсутствует.\n");
    }
    while((f_choice<1)||(f_choice>3));
    
    printf("\nВыберите метод решения уравнения:\n");
    printf("1: метод деления пополам\n");
    printf("2: метод касательных\n");
    do
    {
        printf("\nВведите номер метода: ");
        scanf("%d", &m_choice);
        if((m_choice<1)||(m_choice>2)) printf("Ошибка! Метод под введённым номером отсутствует.\n");
    }
    while((m_choice<1)||(m_choice>2));

    printf("\nВведите параметр c: "); scanf("%f", &c);
    printf("\nВведите параметр d: "); scanf("%f", &d);

    do
    {
        printf("\nВведите точность e (e > 0.000001): ");
        scanf("%f", &e);
        if(e < (float)0.000001) printf("Ошибка! Точность e должна быть больше или равна 0.000001.\n");
    }
    while(e < (float)0.000001);

	if (m_choice == 1) x = method_1(f_choice, c, d, e, &count);
	else x = method_2(f_choice, c, d, e, &count);
    printf("Корень уравнения: %f\n", x);
	printf("Шаг, на котором был вычислен корень: %d\n", count);
}

float method_1(int f_choice, float c, float d, float e, int *count)
{
    float (*currentEquation)(float, float, float);
    currentEquation = f[0][f_choice-1];
    float a, b, mid;
    
    do 
	{
		printf("\nВведите левую границу a (a<b): "); scanf("%f", &a);
		printf("Введите правую границу b (b>a): "); scanf("%f", &b);
		if(a>b) printf("\nОшибка! Левая граница области больше правой.\n");
		else if (sign(currentEquation(a, c, d)) == sign(currentEquation(b, c, d)))
		printf("\nОшибка! Точка пересечения неявно выражена на данном отрезке.\n");
    } while((a > b) || (sign(currentEquation(a, c, d)) == sign(currentEquation(b, c, d))));
    
    do
    {
        mid = (a + b)/2;
        if (sign(currentEquation(a, c, d)) != sign(currentEquation(mid, c, d))) b = mid;
        else a = mid;
		(*count)++;
    } while ((fabs(b-a)>e) && (*count <= 500));

    return mid;
}

float method_2(int f_choice, float c, float d, float e, int *count)
{
    float (*currentEquation)(float, float, float);
    float (*currentDerivative)(float, float, float);
    currentEquation = f[0][f_choice-1];
    currentDerivative = f[1][f_choice-1];
    float x = 10, x0;
    
    do
    {
        x0 = x;
        x = x - (currentEquation(x, c, d) / currentDerivative(x, c, d));
		while ((fabs(x - x0) < e) && (sign(x - e) == sign(x + e)) && (e != 0)) e /= 10;
		(*count)++;
    }
    while ((fabs(x - x0) > e) && (*count <= 500));

    return x;
}

int sign(float x)
{
    int result;
    if (x < 0)  result=-1;
    else if (x == 0) result=0;
    else result = 1;
    return result;
}

float equation_2(float x, float c, float d)
{
    return exp(x * c) - d;
}

float equation_4(float x, float c, float d)
{
    return pow(x, 3) + c * pow(x, 2) + d;
}

float equation_5(float x, float c, float d)
{
    return pow(x, 4) + c * pow(x, 3) - d * x;
}

float derivative_2(float x, float c, float d)
{
    return c * exp(x * c);
}

float derivative_4(float x, float c, float d)
{
    return 3 * pow(x, 2) + 2 * c * x;
}

float derivative_5(float x, float c, float d)
{
    return 4 * pow(x, 3) + 3 * c * pow(x, 2) - d;
}