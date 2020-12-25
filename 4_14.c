#include <stdio.h>
int main ()
{
int n;
printf("Введите год "); scanf("%d",&n);
n-=3;
printf("\n%d",n);

while(n > 60) n-=60;
printf("\n%d",n);
printf("Цвет животного: ");
if (n<=12) printf("Зелёный");
else if (n>=13 && n<=24) printf("Красный");
else if (n>=25 && n<=36) printf("Жёлтый");
else if (n>=37 && n<=48) printf("Белый");
else if (n>=48 && n<=60) printf("Чёрный");

while(n > 12) n-=12;
printf("\n%d",n);
printf("\nНазвание животного: ");
if (n==1) printf("Крыса");
else if (n==2) printf("Корова");
else if (n==3) printf("Тигр");
else if (n==4) printf("Заяц");
else if (n==5) printf("Дракон");
else if (n==6) printf("Змея");
else if (n==7) printf("Лошадь");
else if (n==8) printf("Овца");
else if (n==9) printf("Обезьяна");
else if (n==10) printf("Курица");
else if (n==11) printf("Собака");
else if (n==12) printf("Свинья");
return 0;
}