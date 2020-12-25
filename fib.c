#include <stdio.h>
#include <math.h>
int fib (int x);
int main ()
{
    int x;
	for (x=1; x<=100; x++) printf ("fib(%d) = %d\n", x, fib (x));
	return 0;
}

int fib (int x)
{
    if ((x == 1) || (x == 2)) return 1;
    else return fib(x-1)+fib(x-2);
}