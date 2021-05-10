#include <stdio.h>
#include <math.h>
#include <time.h>

float method_1(void);
float method_2(void);
float equation_2(float, float, float);
float equation_4(float, float, float);
float equation_5(float, float, float);
int sign(float);

int main()
{   
    float (*m_arr[2])(void) = {method_1, method_2};
    int m_choice;
    do
    {
    printf("Выберите метод решения уравнения:\n1 - метод деления пополам\n2 - метод секущей\n");
    scanf("%d", &m_choice);
    if((m_choice<1)||(m_choice>2)) printf("ERR0R!!!\n");
    }
    while((m_choice<1)||(m_choice>2));
    return m_arr[m_choice - 1]();
}

float method_1()
{
    float (*f_arr[3])(float, float, float) = {equation_2, equation_4, equation_5};
    float a, b, c, d, mid, e;
    float (*currentEquation)(float, float, float);
    int f_choice;
    scanf("%d", f_choice);
    currentEquation = f_arr[f_choice-1];
    do
    {
        printf("Введите точность e (e>0): ");
        scanf("%f", &e);
        if(e<=0) printf("ERR0R!!!\n");
    }
    while(e<=0);
    do
    {
    printf("Введите левую границу a (a<b): "); scanf("%f", &a);
    printf("Введите правую границу b (b>a): "); scanf("%f", &b);
    if(a>b) printf("ERR0R!!!\n");
    // проверка чтобы f(a) и f(b) были разного знака
    }
    while(a>b);
    printf("Введите первый параметр c: "); scanf("%f", &c);
    printf("Введите второй параметр d: "); scanf("%f", &d);

    while (fabs(b-a)>e)
    {
        mid = (a + b)/2;
        if (sign(currentEquation(a, c, d)) != sign(currentEquation(mid, c, d))) b = mid;
        else a = mid;
        printf("%f %f %f\n", mid, a, b);
    }
    return (a + b)/2;
}

float method_2()
{
    float c, d, e, x0;
    srand(time(NULL));
    x0 =  rand()%1000;
    float (*d_arr[3])(float, float, float) = {derivative_2, derivative_4, derivative_5};
    float (*currentDerivative)(float, float, float);
    int d_choice;
    scanf("%d", d_choice);
    currentDerivative = d_arr[d_choice-1];
    currentDerivative(x0);
    //производная -ю уравнение прямой(угол наклона и точка) -ю где прямая пересекает 0 -ю прямая пересекает ноль - новый икс 

    return;
}

float equation_2(float x, float c, float d)
{
    return exp(x * c) - d;
}

int sign(float x)
{
    int result;
    if (x < 0)  result=-1;
    else if (x==0) result=0;
    else result=1;
    return result;
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
    return x * c * exp(x * c);
}

float derivative_4(float x, float c, float d)
{
    return 3 * pow(x, 2) + 2 * c * x;
}

float derivative_5(float x, float c, float d)
{
    return 4 * pow(x, 3) + 3 * c * pow(x, 2) - d;
}