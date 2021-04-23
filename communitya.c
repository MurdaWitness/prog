#include <stdio.h>

int main()
{
    int years;
    char first_name[30], last_name[30];
    char position[100];

    FILE *fpeople;

    if ((fpeople = fopen("test.txt", "a")) == NULL)
    printf("\n");
    else
    {
        printf("Введите фамилию, имя, возраст, должность сотрудника:\n");
        scanf("%s%s%d%s", last_name, first_name, &years, position);
        while(!feof(stdin))
        {
            fprintf(fpeople,"%s%s%d%s", last_name, first_name, &years, position);
            scanf("%s%s%d%s", last_name, first_name, &years, position);
        }
    }
    fclose(fpeople);
    return 0;
}