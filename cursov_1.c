//Подключаем стандартную библиотеку ввода-вывода
#include <stdio.h>
//Подключаем математическую библиотеку для получения достоверных значений тангенса
#include <math.h>
//Подключаем стандартную библиотеку для использования команды clear 
#include <stdlib.h>
//Прототип функции, вычисляющей нужное количество членов ряда. Принимает float x и float e
int control(float, float);
//Прототип функции, вычисляющей бесконечную сумму. Принимает float x и int steps
float inf(float, int);

//Главная функция main
void main()
{
    //Очистка экрана перед использованием
    system("clear");
    //Переменные x и e с плавающей точкой
    //Используются для хранения значения угла в градусах и точности соответственно
    float x, e;
    //Целочисленная переменная steps
    //Используется для хранения целого количества членов дроби, нужных для вычисления
    int steps;
    //Переменная tangens с плавающей точкой
    //Используется для хранения значения тангенса, вычисленного с помощью бесконечного ряда
    float tangens;
    do
    {
        //Получаем от пользователя значение x в градусах
        printf("Введите x в градусах: ");
        scanf("%f", &x);
        //Проверка x на кратность 90 градусам. Если x кратен 90, то программа выводит ошибку
		if(fabs(fmodf(x, 180)) == (float)90) printf("Ошибка! Тангенса от 90 градусов не существует.\n");
        //Если пользователь вводит x близкий к 90, то программа выводит предупреждение о том,
        //что при вводе точности меньше 0.001 программа может работать некорректно
		else if((fabs(fmodf(x, 180)) > (float)85) && (fabs(fmodf(x, 180)) < (float)95))	
        printf("Внимание! При исследовании тангенса градусов, близких к 90 не выставляйте точность ниже 0.001.\n");
    }
    //Цикл с постусловием, который не даёт ввести значение тангенса кратное 90
    while (fabs(fmodf(x, 180)) == (float)90);
    
    do
    {
        //Получаем от пользователя значение точности е
        printf("Введите точность e больше или равную 0.000001: ");
        scanf("%f", &e);
        //Проверка точности e. Если точность слишком маленькая, то программа выводит ошибку
        if(e < (float)0.000001) printf("Ошибка! Точность e должна быть больше или равна 0.000001.\n");
    }
    //Цикл с постусловием, который не даёт ввести слишком маленькое значение e 
    while(e < (float)0.000001);
    
    //Перевод x из градусов в радианы для последующих математических операций
    x *= M_PI / 180;
    //Приравнивание переменной steps результата вывода функции control
    steps = control(x, e);
    //Приравнивание переменной tangens результата вывода функции inf
    tangens = inf(x, steps);

    //Вывод количества суммируемых дробей
    printf("Количество шагов равно: %d\n", steps);
    //Вывод значения тангенса
    printf("Бесконечная сумма равна: %f\n", tangens);
}
//Функция control. Вычисляет нужное количество шагов
//Принимает значение x в радианах и значение точности e
int control(float x, float e)
{
    //Объявление целочисленной переменной steps, которая хранит количество шагов
    //Изначально равна нулю
    int step = 0;
    //Объявление переменной result, которая хранит временное значение результата
    //для сравнения с истинным значением тангенса
    float result;
    do
    {
        //Проверка на количество итераций цикла
        if (step < 500) 
        {
            //Если количество итераций соответствует допустимым, то количество членов дроби инкрементируется
            step++;
            //Временному значению result приравнивается значение функции inf от количества шагов steps
            result = inf(x, step);
        }
        else 
        {
            //Если количество итераций было превышено, то программа выводит ошибку
            printf("Ошибка! Количество итераций превысило допустимый порог!\nВыставляется произвольное количество шагов.\n");
            //Экстренный выход из программы
            return 0;
        }
    }
    //Цикл с постусловием, который высчитывает тангенс до тех пор, 
    //пока разница между бесконечным рядом и истинным тангенсом не станет меньше или равной точности e
    while (fabs(result - tan(x)) > e);
    //Возвращает в main нужное количество шагов
    return step;
}
//Функция inf. Рассчитывает значение тангенса
//Принимает значение x в радианах и целочисленное значение количества шагов steps, до которого нужно высчитывать тангенс
float inf(float argument, int step)
{
    //Целочисленная переменная curentOdd
    //Используется для хранения нечётного числа
    int currentOdd;
    //Переменные с плавающей точкой minus и denominator.
    //Minus хранит вычитаемое, denominator - знаменатель.
    float minus = 0, denominator;
    
    //Вычисление текущего нечётного числа
    currentOdd = (step - 1) * 2 + 1;
    //Цикл с предусловием вычисляется до тех пор, пока текущее нечётное положительно
    while(currentOdd > 0)
    {
        //Вычисление знаменателя
        //В переменную текущее нечётное делённое на аргумент x из которого вычитается minus 
        denominator = currentOdd/argument - minus;
        //В вычитаемую переменную minus заносим единицу делённую на знаменатель
        minus = 1/denominator;
        //Текущее нечётное уменьшается на 2
        currentOdd-=2;
    }
    //Возвращаем вычитаемое, т.к. оно удобно делится единицей
    return minus;
}