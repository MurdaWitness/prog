#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char fileName[30];

struct entry
{
    int date;
    int month;
    int year;
    int hour;
    int minute;
    char note[255];
};

int main()
{
    system("clear");
    printf("Календарь-ежедневник приветствует вас!"); 
    if(UserMenu())
    ShowMenu();
    return 0;
}

void ShowMenu()
{
    int choice;
    do
    {
        system("clear");
        printf("\tМеню функций:\n"); 
        printf("1 - показать все события пользователя\n"); 
        printf("2 - добавить событие\n"); 
        printf("3 - удалить событие\n"); 
        printf("4 - редактировать событие\n"); 
        printf("5 - сменить пользователя\n"); 
        printf("6 - выйти\n");
        printf("\nВыбор команды: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ShowAllNotes();
            break;
        case 2:
            AddNote();
            break;
        case 3:
            RemoveNote();
            break;
        case 4:
            EditNote();
            break;
        case 5:
            if(UserMenu())
            break;
        case 6:
        printf("Спасибо за использование календаря-ежедневника!\n");
        printf("Хорошего и продуктивного дня!\n");
        return 0;
        
        default:
            printf("Ошибка! Неверно набран номер.\n");
            break;
        }
    }
    while(1);
}

int UserMenu()
{
    int choice;
    FILE *fUser;
    do
    {
        printf("\nЧто вы хотите сделать?\n");
        printf("1 - выбрать существующего пользователя\n");
        printf("2 - создать нового пользователя\n");
        printf("3 - удалить существующего пользователя\n");
        printf("\nВыбор команды: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nВведите имя пользователя: ");
            scanf("%s", fileName);
            strcat(fileName, ".txt");
            if ((fUser = fopen(fileName, "r")) == NULL)
            {
            printf("\nОшибка! Пользователь не существует!\n\n");
            break;
            }
            else 
            {
                printf("\nОсуществляю вход...\n");
                system ("sleep 0.5");
                return 1;
            }
            
            break;
        case 2:
            printf("Введите имя пользователя: ");
            scanf("%s", fileName);
            strcat(fileName, ".txt");
            if ((fUser = fopen(fileName, "w")) == NULL)
            {
            printf("Ошибка! Пользователь не может быть создан!");
            break;
            }
            else 
            {
                printf("Пользователь создан.");
                system ("sleep 0.5");
                system ("clear");
                return 1;
            }
            break;
        case 3:
            printf("Введите имя пользователя: ");
            scanf("%s", fileName);
            strcat(fileName, ".txt");
            if (remove(fileName) != NULL)
            {
            printf("Ошибка! Пользователь не может быть удалён!");
            break;
            }
            else 
            {
                printf("Пользователь успешно удалён.");
                system ("sleep 0.5");
                system ("clear");
            }
            break;
        default:
            printf("aboba\n");
            break;
        }
    }
    while(1);
    /*
    printf("Введите имя пользователя: ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");
    printf("%s\n", fileName);
    if ((fUser = fopen(fileName, "а+")) == NULL)
    printf("Ошибка! Пользователь не может быть создан");
    else 
    {
        printf("Готово");
        system ("sleep 0.5");
        fclose(fUser);
    }
    */
    /*
    спросить у пользователя название файла
    открыть файл на запись
    если не открылся то стопэ
    если открылся то запомнить название файла
    закрыть файл
    */
}

void ShowAllNotes()
{
    printf("a\n");
    /*Открываем файл
    считываем все структуры
    по мере считывания, выводим на экран
    Закрываем*/
}

void AddNote()
{
    printf("a\n");
    /*создать временную структуру с помощью ReadStructure
    открыть файл на дозапись "а"
    проверить с Check Есть ли заметка на эту дату
    если есть то прерываемся, иначе заносим
    занести структуру в файл
    закрыть файл*/
}

struct entry* ReadStructure()
{
    printf("a\n");
   /*создать временную структуру
    спросить у мользователя Ч М Г
    спросить какая заметка
    Занести данные в структуру
    Вернуть структуру
    */
}

void EditNote()
{
    printf("a\n");
    /*с помощью ReadStruct спрашиваем структуру
    если структура существует(чекаем Check) то перезаписываем
    иначе такой заметки нема*/
}

void RemoveNote()
{
    printf("a\n");
    /*юзер вводит Ч М Г
    используем Чек с указанным Ч М Г
    если нашли, то удаляем структ из файла
    если не нашли, значит ничего
    */
}

int Check(int date, int month, int year, int hour, int minute)
{
    printf("a\n");
    return 0;
    /*открыть файл на чтение
    если находится структура с укзанным чмг, возвращаем 1 иначе 0*/
}
