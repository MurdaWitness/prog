#include <stdio.h>
#include <math.h>

float fun(float, float);

int main()
{
	float e, sum, x, check;
	int it = 2;
	printf("Введите аргумент тангенса (в градусах): ");
	scanf("%f", &x);
	x = x * M_PI / 180;
	printf("Введите точность : ");
	scanf("%f", &e);
	check = tan(x);
	sum = fun(x, 1);
	while ((sum <= check - e) || (sum >= check + e))
	{
		sum = fun(x, it);
		it++;
	}
	printf("Полученное значение: %f\nСкорость схождения: %d\nАргумент ряда: %f", sum, it, x);
	return 0;		
}

float fun(float x, float it)
{
	float result = 1, temp = 1;
	it = (it - 1) * 2 + 1;
	while (it > 0)
	{
		temp = it / x - result;
		result = 1 / temp;
		it -= 2;
	}
	return result;
}
