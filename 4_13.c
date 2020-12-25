#include <stdio.h>
int main ()
{
int D,M;
printf("Введите день рождения "); scanf("%d",&D);
printf("Введите месяц рождения "); scanf("%d",&M);
printf("Ваш знак зодиака ");
if (D>=20&&M==1||D<=18&&M==2) printf("Водолей");
else if (D>=19&&M==2||D<=20&&M==3) printf("Рыбы");
else if (D>=21&&M==3||D<=19&&M==4) printf("Овен");
else if (D>=20&&M==4||D<=20&&M==5) printf("Телец");
else if (D>=21&&M==5||D<=21&&M==6) printf("Близнецы");
else if (D>=22&&M==6||D<=22&&M==7) printf("Рак");
else if (D>=23&&M==7||D<=22&&M==8) printf("Лев");
else if (D>=23&&M==8||D<=22&&M==9) printf("Дева");
else if (D>=23&&M==9||D<=22&&M==10) printf("Весы");
else if (D>=23&&M==10||D<=22&&M==11) printf("Скорпион");
else if (D>=23&&M==11||D<=21&&M==12) printf("Стрелец");
else if (D>=22&&M==12||D<=19&&M==1) printf("Козерог");
return 0;
}
