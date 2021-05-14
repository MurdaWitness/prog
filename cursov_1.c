#include <stdio.h>
#include <math.h>

float inf(float, int);
int control(float, float);

void main()
{
    float x, e;
    int steps;
    float tangens;
    do
    {
        printf("Введите x в градусах: ");
        scanf("%f", &x);
		if(fabs(fmodf(x, 180)) == (float)90) printf("Ошибка! Тангенса от 90 градусов не существует.\n");
		else if((fabs(fmodf(x, 180)) > (float)85) && (fabs(fmodf(x, 180)) < (float)95))	printf("Внимание! При исследовании тангенса градусов, близких к 90 не выставляйте точность ниже 0.001.\n");
        
    }
    while (fabs(fmodf(x, 180)) == (float)90);
    
    do
    {
        printf("Введите точность e больше или равна 0.000001: ");
        scanf("%f", &e);
        if(e < (float)0.000001) printf("Ошибка! Точность e должна быть больше или равна 0.000001.\n");
    }
    while(e < (float)0.000001);
    
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
        if (step < 100) step++;
        else 
        {
            printf("Ошибка! Количество итераций превысило допустимый порог!\nВыставляется произвольное количество шагов.\n");
            return 1;
        }
        result = inf(x, step);
    }
    while (fabs(result - tan(x)) > e);
    return step;
}

float inf(float argument, int step)
{
    int currentOdd;
    float minus = 0, denominator;
    
    if (step == 1) currentOdd = step;
    else currentOdd = (step - 1) * 2 - 1;
    while(currentOdd >= 1)
    {
        denominator = currentOdd/argument - minus;
        minus = 1/denominator;
        currentOdd-=2;
    }
    return minus;
}