#include <stdio.h>
int main ()
{
    int years;
    char first_name [30], last_name [30];
    char position [100];
    FILE * fpeople;
    if ((fpeople = fopen ("test", "r")) == NULL)
    printf ("ERROR!!!\n");
    else
    {
        fscanf (fpeople, "%s%s%d%s", last_name, first_name, &years, position);
        while (!feof (fpeople))
        {
            printf ("%s%s%d%s", last_name, first_name, years, position);
            fscanf (fpeople, "%s%s%d%s", last_name, first_name, &years, position);
        }
        fclose (fpeople);
    }
    return 0;
}