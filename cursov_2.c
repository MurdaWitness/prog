#include <stdio.h>
#include <math.h>
#include <time.h>

void method_1(void);
void method_2(void);
float equation_2(float, float, float);
float equation_4(float, float, float);
float equation_5(float, float, float);
float derivative_2(float, float, float);
float derivative_4(float, float, float);
float derivative_5(float, float, float);
int sign(float);

int main()
{   
    void (*m_arr[2])(void) = {method_1, method_2};
    int m_choice;
    printf("Выберите метод решения уравнения:\n");
    printf("1 - метод деления пополам\n");
    printf("2 - метод касательных\n");
    do
    {
    printf("Введите номер метода: ");
    scanf("%d", &m_choice);
    if((m_choice<1)||(m_choice>2)) printf("Ошибка! Метод под введённым номером отсутствует.\n");
    }
    while((m_choice<1)||(m_choice>2));
    m_arr[m_choice - 1]();
    return 0;
}

void method_1()
{
    float (*f_arr[3])(float, float, float) = {equation_2, equation_4, equation_5};
    float a, b, c, d, mid, e;
    float (*currentEquation)(float, float, float);
    int f_choice;
    printf("Выберите номер уравнения:\n");
    printf("1: y = e^xc - d\n");
    printf("2: y = x^3 + cx^2 + d\n");
    printf("3: y = x^4 + cx^3 - dx\n");
    printf("Введите номер уравнения: ");
    scanf("%d", &f_choice);
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
        //printf("%f %f %f\n", mid, a, b);
    }
    //return (a + b)/2;
}

void method_2()
{
    float c = 2, d = 7, e = 0.001f, x, x0, temp;
    //srand(time(NULL));
    x0 =  27;//rand()%1000;
    float (*f_arr[3])(float, float, float) = {equation_2, equation_4, equation_5};
    float (*currentEquation)(float, float, float);
    float (*d_arr[3])(float, float, float) = {derivative_2, derivative_4, derivative_5};
    float (*currentDerivative)(float, float, float);
    int choice;
    printf("Выберите номер уравнения:\n");
    printf("1: y = e^xc - d\n");
    printf("2: y = x^3 + cx^2 + d\n");
    printf("3: y = x^4 + cx^3 - dx\n");
    printf("Введите номер уравнения: ");
    scanf("%d", &choice);
    currentEquation = f_arr[choice-1];
    currentDerivative = d_arr[choice-1];
    do
    {
        x = x0 - (currentEquation(x0, c, d)/currentDerivative(x0, c, d));
        printf("%f %f\n", x0, x);
        temp = x0;
        x0 = x;
    }
    while(fabs(x-temp)>e);
    

    //currentDerivative(x0, c, d);
    //производная -ю уравнение прямой(угол наклона и точка) -ю где прямая пересекает 0 -ю прямая пересекает ноль - новый икс 

    //return x1;
}

int sign(float x)
{
    int result;
    if (x < 0)  result=-1;
    else if (x==0) result=0;
    else result=1;
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