#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct point
{
    int x, y, z;
	float range;
};

int main()
{
    int n, chosen, minrange;
    float range; 
    printf("Введите кол-во точек: "); scanf("%d", &n);
    struct point ptr[n];
    for(int i = 0; i<n; i++)
    {
        printf("\nТочка № %d\n", i+1);
        printf("Координаты по x: "); scanf("%d", &ptr[i].x);
        printf("Координаты по y: "); scanf("%d", &ptr[i].y);
        printf("Координаты по z: "); scanf("%d", &ptr[i].z);
		ptr[i].range = sqrt(pow(ptr[i].x, 2) + pow(ptr[i].y, 2) + pow(ptr[i].z, 2));
		printf("Расстояние от центра координат: %0.4f", ptr[i].range); 
		printf("\n");
    }
    for(int i = 1; i<=n; i++)
    {
        if(ptr[i].range < minrange) 
		{
			minrange = ptr[i].range;
			chosen = i;
		}
    }
	printf("\nТочка под номером %d имеет координаты (%d,%d,%d) и наименьший радиус %0.4f", chosen+1, ptr[chosen].x, ptr[chosen].y, ptr[chosen].z, ptr[chosen].range);
    return 0;
}
