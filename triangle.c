#include <stdio.h>
int main()
{
	int h,l;
	printf ("Эта программа рисует треугольник.\n");
	printf ("И где я в этой жизни свернул не туда, раз занимаюсь такой бесполезной хуйнёй?.....\n");
	printf ("Ладно, введите высоту треугольника: \n");
	scanf ("%d", &h);
	l = h;
	for (int j = 0; j < h; j++)
	{
		for (int i = 1; i < h * 2 ; i++)
		{
			if ((i == l - j) || (i == l + j)|| (j == h-1)) printf("*"); else printf(" ");

		}
		printf("\n");
	}
	
	return 0;
}
