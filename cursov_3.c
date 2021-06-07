#include <stdio.h>
#include <time.h>

char fileName[30];

struct entry
{
    int date;
    int month;
    int year;
    char note[255];
};

int main()
{
    LoadUser();
    ShowMenu();
    return 0;
}

void ShowMenu()
{
    int choice;
    do
    {
        choice = MakeChoice();
        switch (choice)
        {
        case 0:
            ShowAllData();
            break;
        case 1:
            AddData();
            break;
        case 2:
            RemoveData();
            break;
        case 3:
            EditData();
            break;
        case 4:
            LoadUser();
            break;
        case 5:
        return 0;
        
        default:
            break;
        }
    }
    while(1);
}

void LoadUser()
{
    /*спросить у пользователя название файла
    открыть файл на запись
    если не открылся то стопэ
    если открылся то запомнить название файла
    закрыть файл
    */
}

void ShowAllData()
{
    /*Открываем файл
    считываем все структуры
    по мере считывания, выводим на экран
    Закрываем*/
}

void AddData()
{
    /*создать временную структуру с помощью ReadStructure
    открыть файл на дозапись "а"
    проверить с Check Есть ли заметка на эту дату
    если есть то прерываемся, иначе заносим
    занести структуру в файл
    закрыть файл*/
}

struct entry* ReadStructure()
{
   /*создать временную структуру
    спросить у мользователя Ч М Г
    спросить какая заметка
    Занести данные в структуру
    Вернуть структуру
    */
}

void EditData()
{
    /*с помощью ReadStruct спрашиваем структуру
    если структура существует(чекаем Check) то перезаписываем
    иначе такой заметки нема*/
}

void RemoveData()
{
    /*юзер вводит Ч М Г
    используем Чек с указанным Ч М Г
    если нашли, то удаляем структ из файла
    если не нашли, значит ничего
    */
}

int Check(int date, int month, int year)
{
    /*открыть файл на чтение
    если находится структура с укзанным чмг, возвращаем 1 иначе 0*/
}