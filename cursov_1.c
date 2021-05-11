#include <stdio.h>
#include <math.h>

float inf(float, int);
int control(float, float);

void main()
{
    float x, e;
    int steps;
    float tangens;
    /*for (int i = 0; i <= 360; i+=15)
    {
        x = i;
        x *= M_PI / 180;
        printf("%f\n", tan(x));
    }*/
    do
    {
        printf("Введите точность e больше или равна 0.000001: ");
        scanf("%f", &e);
        if(e < (float)0.000001) printf("Ошибка! Точность e должна быть больше или равна 0.000001.\n");
    }
    while(e < (float)0.000001);
    
    printf("Введите x в градусах: ");
    scanf("%f", &x);
    if(x<0) while(x<0) x+=360;
    // проверка на 90 градусов + вырубание программы после 1000 шагов
    
    x *= M_PI / 180;
    steps = control(x, e);
    tangens = inf(x, steps);

    printf("Количество шагов равно: %d\n", steps);
    printf("Бесконечная сумма равна: %f\n", tangens);
}

int control(float x, float e)
{
    int step = 0;
    float result;
    do
    {
        step++;
        result = inf(x, step);
    }
    while (fabs(result - tan(x)) > e);
    return step;
}

float inf(float argument, int step)
{
    int currentOdd = (step - 1) * 2 - 1;
    float minus = 0, denominator;
    while(currentOdd >= 1)
    {
        denominator = currentOdd/argument - minus;
        minus = 1/denominator;
        currentOdd-=2;
    }
    return minus;
}