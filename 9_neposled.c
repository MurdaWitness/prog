#include <stdio.h>
#include <stdlib.h>

struct client
{
    char last_name[10];
    char first_name[10];
    char birthday[8];
};

void show(FILE *f)
{
    if (())
}

int main()
{
    FILE *f;
    int choice;
    printf("Что вы хотите сделать?\n");
    printf("1 - просмотреть текущую БД\n");
    printf("2 - изменить текущую БД\n");
    printf("3 - создать новую БД\n");
    
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        
        break;

    case 2:
        
        break;

    case 3:
        
        break;
    
    default:
        break;
    }
    int N;
    printf("N=");
    scanf("%d", &N);
    srand(time(NULL));
    int i;
    float r;
    if ((f = fopen("data.dat", "w")) == NULL)
    printf("Не могу открыть файл для записи");
    else
    {
        for (i = 0; i < N; i++)
        {
            printf("%f\n", r = (float)(rand() % 100) / 100);
            fwrite(&r, sizeof(float), 1, f);
        }
        fclose(f);
    }
    return 0;
}