#include <stdio.h>
#include <math.h>

float inf(float, int);
int control(float, float);

void main()
{
    float x, e;
    int steps;
    do
    {
        printf("Введите точность e (e>0): ");
        scanf("%f", &e);
        if(e<=0) printf("ERR0R!!!\n");
    }
    while(e<=0);
    do
    {
        printf("Введите x в градусах: ");
        scanf("%f", &x);
        if(x<0) printf("ERR0R!!!\n");
    }
    while(x<0);
    x *= M_PI / 180;
    steps = control(x, e);
    printf("Количество шагов равно: %d\n", steps);
    printf("Бесконечная сумма равна: %f\n", inf(x, steps));
}

int control(float x, float e)
{
    int step = 1;
    float res;
    do
    {
        res = inf(x, step);
        step++;
    }
    while (fabs(res-tan(x))>e);
    return step-1;
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