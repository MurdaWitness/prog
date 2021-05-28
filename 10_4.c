#include <stdio.h>
#include <ctype.h>

void main()
{
    char a[50], *b = NULL;
    long int n;
    printf("Введите строку"); scanf("%s", a);
    n = strtol(a, &b, 0);
    printf("%ld\n", n);
    while(!(isdigit(*b))&&((*b)!='\0')) b++;
    n = strtol(b, &b, 0);
    printf("%ld\n", n);
}