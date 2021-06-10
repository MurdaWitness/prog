//Подключаем стандартную библиотеку ввода-вывода
#include <stdio.h>
//Подключаем математическую библиотеку для получения достоверных значений тангенса
#include <math.h>
//Подключаем стандартную библиотеку для использования команды clear 
#include <stdlib.h>

//Прототип метода деления отрезков пополам
//Принимают номер уравнения, 2 параметра,
//точность и указатель на счётчик
float method_1(int, float, float, float, int *);
//Прототип метода касательных
//Принимают номер уравнения, 2 параметра,
//точность и указатель на счётчик
float method_2(int, float, float, float, int *);
//Прототипы функций уравнений
//Принимают аргумент и 2 параметра
float equation_1(float, float, float);
float equation_2(float, float, float);
float equation_3(float, float, float);
float equation_4(float, float, float);
float equation_5(float, float, float);
float equation_6(float, float, float);
//Прототипы функций производных от уравнений
//Принимают аргумент и 2 параметра
float derivative_1(float, float, float);
float derivative_2(float, float, float);
float derivative_3(float, float, float);
float derivative_4(float, float, float);
float derivative_5(float, float, float);
float derivative_6(float, float, float);
/*Статический двумерный массив функций уравнений и их 
производных. Используется для удобного доступа из любого метода.
1-ая мерность определяет, это уравнение первообразная или производная,
2-ая - номер самого уравнения. Инициализируется самими уравнениями.*/
float (*f[2][6])(float, float, float) = {{equation_1, equation_2, equation_3, equation_4, equation_5, equation_6}, {derivative_1, derivative_2, derivative_3, derivative_4, derivative_5, derivative_6}};
//Прототип функции, вычисляющей знак уравнения
int sign(float);


//Главная функция main
void main()
{   
    //Очистка экрана перед использованием
    system("clear");
    /*Целочисленные переменные f_choice, m_choice и count.
    Хранят номер уравнения, номер метода и счётчик соответственно.
    Изначально счётчик инициализируется нулём.*/
    int f_choice, m_choice, count = 0;
    /*Переменные с плавающей точкой c, d, e и x.
    c и d это параметры, задаваемые пользователем, e - точность вычислений.
    Переменная x хранит результат, вычисленный одним из методов.*/
    float c, d, e, x;

    //Выбор уравнения
    printf("Выберите номер уравнения:\n");
    printf("1: y = e^cx - d\n");
    printf("2: y = x^3 + cx^2 + d\n");
    printf("3: y = x^4 + cx^3 - dx\n");
    printf("4: y = cx^3 + dx^2 - cx\n");
    printf("5: y = cx^8 - dx^5\n");
    printf("6: y = cx^8 - dx^4 + x\n");
    //Получение номера уравнения от пользователя 
    do
    {
        printf("\nВведите номер уравнения: ");
        scanf("%d", &f_choice);
        //Ошибка, говорит о неверности введённого номера уравнения
        if((f_choice<1)||(f_choice>6)) printf("Ошибка! Уравнение под введённым номером отсутствует.\n");
    }
    //Цикл с постусловием, не даёт ввести неверный номер уравнения 
    while((f_choice<1)||(f_choice>6));
    
    //Выбор метода
    printf("\nВыберите метод решения уравнения:\n");
    printf("1: метод деления пополам\n");
    printf("2: метод касательных\n");
    //Получение номера метода от пользователя
    do
    {
        printf("\nВведите номер метода: ");
        scanf("%d", &m_choice);
        //Ошибка, говорит о неверности введённого номера метода
        if((m_choice<1)||(m_choice>2)) printf("Ошибка! Метод под введённым номером отсутствует.\n");
    } 
    //Цикл с постусловием, не даёт ввести неверный номер метода 
    while((m_choice<1)||(m_choice>2));

    //Получение параметров от пользователя
    printf("\nВведите параметр c: "); scanf("%f", &c);
    printf("\nВведите параметр d: "); scanf("%f", &d);

    //Получение точности от пользователя
    do
    {
        printf("\nВведите точность e (e >= 0.000001): ");
        scanf("%f", &e);
        //Ошибка, говорит о вводе слишком маленькой точности
        if(e < (float)0.000001) printf("Ошибка! Точность e должна быть больше или равна 0.000001.\n");
    } 
    //Цикл с постусловием, не даёт ввести слишком маленькую точность 
    while(e < (float)0.000001);

    /*Вычисление корня уравнения функциями методов, осуществлённое конструкцией if/else
	В методы передаётся номер выбранного уравнения, 2 параметра, точность и ссылка на переменную счётчика*/
	if (m_choice == 1) x = method_1(f_choice, c, d, e, &count);
	else x = method_2(f_choice, c, d, e, &count);
    //Вывод на экран вычисленного корня
    printf("Корень уравнения: %f\n", x);
    //Вывод на экран количества итераций
	printf("Шаг, на котором был вычислен корень: %d\n", count);
}

/*Функция вычисления корня методом деления отрезка пополам
Принимает номер выбранного уравнения f_choice, параметры c и d,
точность e и ссылка на счётчик count*/
float method_1(int f_choice, float c, float d, float e, int *count)
{
	/*Для удобства записи вводим новый указатель, 
    который будет ссылаться на выбраное уравнение*/
    float (*currentEquation)(float, float, float);
	//Инициализируем указатель уравнением 
    currentEquation = f[0][f_choice-1];
	/*Переменные с плавающей точкой a, b и mid.
    Хранят левую границу отрезка, правую границу отрезка и середину отрезка соответственно.*/
    float a, b, mid;
    
	//Получение границ отрезка от пользователя
    do 
	{
		printf("\nВведите левую границу a (a<b): "); scanf("%f", &a);
		printf("Введите правую границу b (b>a): "); scanf("%f", &b);
		//Проверка, чтобы левая граница была больше правой
		if(a>b) printf("\nОшибка! Левая граница области больше правой.\n");
		/*Сравнение знаков функции на краях введённого отрезка.
		В случае, если знаки равны, то точка пересечения на данном отрезке считается неявной,
		и программа попросит пользователя ввести иные границы отрезка*/
		else if (sign(currentEquation(a, c, d)) == sign(currentEquation(b, c, d)))
		printf("\nОшибка! Точка пересечения неявно выражена на данном отрезке.\n");
    } 
	/*Цикл с постусловием, не допускает того, чтобы левая граница была больше правой
    а также сравнивает знаки функции на границах отрезка*/
	while((a > b) || (sign(currentEquation(a, c, d)) == sign(currentEquation(b, c, d))));
    
	//Калькуляционный цикл
    do
    {
		//Высчитывает середину отрезка
        mid = (a + b)/2;
		/*Если знак функции на левой границе не равен знаку функции в середине отрезка, 
		то середина отрезка становится правой границей */
        if (sign(currentEquation(a, c, d)) != sign(currentEquation(mid, c, d))) b = mid;
		//Иначе, середина отрезка становится левой границей
        else a = mid;
		//Увеличивает счётчик на единицу
		(*count)++;
        //Сообщение об ошибке при выходе за границы допустимого количества итераций
        if((*count)>=500) 
        printf("\nОшибка! Превышено допустимое количество итераций!\n");
    } 
	/*Цикл с постусловием, сравнивает разницу левой и правой границами отрезка,
    а также проверяет выход за границы допустимого количества итераций*/
	while ((fabs(b-a)>e) && (*count < 500));

    return mid;
}

/*Функция вычисления корня методом касательных.
Принимает номер выбранного уравнения f_choice, параметры c и d,
точность e и ссылка на счётчик count*/
float method_2(int f_choice, float c, float d, float e, int *count)
{
    /*Для удобства записи вводим 2 новых указателя, 
    которые будут ссылаться на выбраное уравнение и соответствующую производную*/
    float (*currentEquation)(float, float, float);
    float (*currentDerivative)(float, float, float);
    //Инициализируем указатели уравнением и производной 
    currentEquation = f[0][f_choice-1];
    currentDerivative = f[1][f_choice-1];
    /*Переменные с плавающей точкой x и x0 хранят приближённые значения функции.
    x инициализируется числом 10, для проведения наиболее стабильных вычислений*/
    float x = 10, x0;
	//Калькуляционный цикл
    do
    {
        //Приравнивает старое приближенное значение x к новому 
        x0 = x;
        /*Отнимает от x значение функции в точке делённое на значение производной в точке
        Это есть новое приближённое значение*/
        x -= currentEquation(x, c, d) / currentDerivative(x, c, d);
        /*Проверка знаков функции на краях отрезка.
        Если разница между приближёнными значениями меньше точности, 
        точность неравна нулю, но знаки функции на краях отрезка равны, 
        то точность уменьшается на 1 разряд, а вычисление продолжается*/
		while ((fabs(x - x0) < e) && (sign(x - e) == sign(x + e)) && (e != 0)) e /= 10;
        //Увеличивает счётчик итераций на единицу
		(*count)++;
        //Сообщение об ошибке при выходе за границы допустимого количества итераций
        if((*count)>=500) 
        printf("\nОшибка! Превышено допустимое количество итераций!\n");
    } 
    /*Цикл с постусловием, сравнивает разницу между старым и новым приближёнными значениями,
    а также проверяет выход за границы допустимого количества итераций*/
    while ((fabs(x - x0) > e) && (*count < 500));

    return x;
}

/*Функция sign, вычисляет знак полученного аргумента. 
Создана для более удобных знаковых операций.
Принимает значение с плавующей точкой, 
а возвращает целочисленный результат со знаком*/
int sign(float x)
{
    //целочисленная переменная, хранящая результат
    int result;
    //если число меньше нуля, то результат отрицательный
    if (x < 0)  result=-1;
    //если число равно нулю, то и результат равен нулю
    else if (x == 0) result=0;
    //если число больше нуля, то результат положительный
    else result = 1;
    //возвращает результат
    return result;
}


/*Функции уравнений.
Принимают аргумент x и параметры c и d.
Возвращают вычисленное значение выражения.*/
float equation_1(float x, float c, float d)
{
    return exp(c * x) - d;
}

float equation_2(float x, float c, float d)
{
    return pow(x, 3) + c * pow(x, 2) + d;
}

float equation_3(float x, float c, float d)
{
    return pow(x, 4) + c * pow(x, 3) - d * x;
}
float equation_4(float x, float c, float d)
{
    return c * pow(x, 3) + d * pow(x, 2) - c * x;
}
float equation_5(float x, float c, float d)
{
    return c * pow(x, 8) - d * pow(x, 5);
}
float equation_6(float x, float c, float d)
{
    return c * pow(x, 8) - d * pow(x, 4) + x;
}

/*Функции производных уравнений.
Принимают аргумент x и параметры c и d.
Возвращают вычисленное значение выражения.*/
float derivative_1(float x, float c, float d)
{
    return c * exp(c * x);
}

float derivative_2(float x, float c, float d)
{
    return 3 * pow(x, 2) + 2 * c * x;
}

float derivative_3(float x, float c, float d)
{
    return 4 * pow(x, 3) + 3 * c * pow(x, 2) - d;
}
float derivative_4(float x, float c, float d)
{
    return 3 * c * pow(x, 2) + 2 * d * x - c;
}
float derivative_5(float x, float c, float d)
{
    return 8 * c * pow(x, 7) - 5 * d * pow(x, 4);
}
float derivative_6(float x, float c, float d)
{
    return 8 * c * pow(x, 7) - 4 * d * pow(x, 3) + 1;
}