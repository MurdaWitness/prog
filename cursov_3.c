//Импорт библиотек
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Структура, хранящая в себе событие в ежедневнике
struct entry
{
    //Количество секунд с начала эпохи. Также служит ключом для идентификации записи
    long long int timestamp;
    //Заметка, описывающая событие
    char note[255];
};

//Имя текущего профиля
char profile[30];

//Загрузка профиля или его создание
void LoadProfile();
//Основное меню, в котором производится выбор действий
void MainMenu();
//Показывает все записи из текущего профиля
void ShowAllEntries();
//Показывает записи из текущего профиля на ближайшие X дней
void ShowNearEntries();
//Добавить в текущий профиль новую запись
void AddEntry();
//Редактировать запись
void EditEntry();
//Удалить запись
void DeleteEntry();
//Удалить все записи, которые уже прошли
void DeleteOldEntries();

//Проверка существования записи
int EntryExists(long long int check);
//Считывает запись с клавиатуры
int ReadEntryFromUser(struct entry *data);
//Считывает только дату с клавиатуры
int ReadDateFromUser(struct entry *data);

int main()
{
    system("clear");
    //Перед переходом в главное меню нужно выбрать профиль
    LoadProfile();
    MainMenu();
    return 0;
}

void MainMenu()
{
    int choice;
    while(1)
    {
        //Вывод вариантов действий
        printf("\n=====Главное меню=====\n");
        printf("Имя профиля: %s\n", profile);
        printf("0 - выйти\n");
        printf("1 - показать все события\n");
        printf("2 - показать ближайшие события\n");
        printf("3 - добавить событие\n");
        printf("4 - редактировать событие\n");
        printf("5 - удалить событие\n");
        printf("6 - удалить все старые события\n");
        printf("7 - сменить профиль\n");
        printf("Выбор команды: ");
        scanf("%d", &choice);
        
        //Обработка выбора пользователя
        switch(choice)
        {
            case 0:
                return;
            case 1:
                ShowAllEntries();
                break;
            case 2:
                ShowNearEntries();
                break;
            case 3:
                AddEntry();
                break;
            case 4:
                EditEntry();
                break;
            case 5:
                DeleteEntry();
                break;
            case 6:
                DeleteOldEntries();
                break;
            case 7:
                LoadProfile();
                break;
        }
    }
}

void LoadProfile()
{
    //Считывание имени профиля, которое также является именем файла
    printf("\nВведите имя профиля: ");
    scanf("%s", profile);
    
    //В случае если такого профиля не существует, создается новый файл
    FILE *file = fopen(profile, "a");
    if(file == NULL)
    {
        printf("Не удалось создать файл.");
        exit(1);
    }
    
    fclose(file);
}

void ShowAllEntries()
{
    //Структура, хранящая данные заметки при считывании файла
    struct entry data;
    //Структура, хранящая данные о времени заметки
    struct tm *datetime;
    
    //Открытие файла
    FILE *file = fopen(profile, "r");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    printf("\n=====Все события=====\n");
    
    //Вывод всех записей
    while(fread(&data, sizeof(struct entry), 1, file))
    {
        //Считывание времени заметки
        time_t timestamp = data.timestamp;
        //Преобразование времени заметки в формат даты
        datetime = localtime(&timestamp);
        //Вывод даты из структуры
        printf("%s", asctime(datetime));
        //Вывод текста заметки
        printf("%s\n", data.note);
        printf("----------\n");
    }
    
    fclose(file);
}

void ShowNearEntries()
{
    //Структура, хранящая данные заметки при считывании файла
    struct entry data;
    //Структура, хранящая данные о времени заметки
    struct tm *datetime;
    
    //Открытие файла
    FILE *file = fopen(profile, "r");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    //Ввод количества дней в будущем, среди которых выводить записи
    printf("\nВведите, на какое ближайшее количество дней вывести события: ");
    int days;
    scanf("%d", &days);
    time_t now, upperend;
    time(&now);
    upperend = now + 86400 * days;
    
    printf("\n=====Ближайшие события=====\n");
    //Вывод всех записей, которые наступят в течение указанного количества дней
    while(fread(&data, sizeof(struct entry), 1, file))
    {
        //Считывание времени заметки
        time_t timestamp = data.timestamp;
        
        //Выводятся только заметки за будущие дни. Заметки из прошлого и слишком дальние заметки игнорируются
        if(timestamp > now && timestamp < upperend)
        {
            //Преобразование времени заметки в формат даты
            datetime = localtime(&timestamp);
            //Вывод даты из структуры
            printf("%s", asctime(datetime));
            //Вывод текста заметки
            printf("%s\n", data.note);
            printf("----------\n");
        }
    }
    
    fclose(file);
}

void AddEntry()
{
    //Структура, хранящая заметку, которую нужно внести в ежедневник
    struct entry data;
    
    //Если неправильно введены данные, выход
    if(!ReadEntryFromUser(&data)) return;
    
    //Нельзя добавить больше чем одну запись на конкретное время. Если запись уже существует, выход
    if(EntryExists(data.timestamp))
    {
        printf("Событие на заданное время уже существует. Возвращаюсь в главное меню.\n");
        return;
    }
    
    //Открытие файла
    FILE *file = fopen(profile, "a");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    //Запись события
    fwrite(&data, sizeof(struct entry),1,file);
    fclose(file);
}

int EntryExists(long long int check)
{
    //Открытие файла
    FILE *file = fopen(profile, "r");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    struct entry data;
    struct tm *datetime;
    //Проверка всех записей на совпадение даты
    while(fread(&data, sizeof(struct entry), 1, file))
    {
        //Если запись существует, возврат 1
        if(check == data.timestamp) 
        {
            fclose(file);
            return 1;
        }
    }
    //Иначе, возврат 0
    fclose(file);
    return 0;
}

int ReadEntryFromUser(struct entry *data)
{
    //Создание структуры, хранящей дату
    struct tm *datetime = malloc(sizeof(struct tm));
    memset(datetime, 0, sizeof(struct tm));
    
    //Считывание даты по частям
    int year, month, day, hour, minute;
    printf("\nВведите дату и время в формате ГГГГ ММ ДД чч мм: ");
    scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);
    //Время вычисляется начиная с 1900 года, так что нужно вычислить, сколько прошло лет с этого года
    datetime->tm_year = year - 1900;
    //Месяц вводится в удобном пользователю формате, а хранится в диапазоне от 0 до 11, так что его нужно преобразовать
    datetime->tm_mon = month - 1;
    datetime->tm_mday = day;
    datetime->tm_hour = hour;
    datetime->tm_min = minute;    
    
    //Исходя из даты вычисляется количество секунд, прошедших с начальной отметки
    data->timestamp = mktime(datetime);
    
    //Если дата неправильная, выход
    if(data->timestamp == -1)
    {
        printf("Некорректная дата.\n");
        return 0;
    }
    
    //Считывание заметки
    printf("Введите вашу заметку: ");
    /*Такая конструкция обеспечивает считывание строки с пробелами. Первая часть %*с отбрасывает перевод строки, 
    оставшийся с предыдущего ввода, средняя часть считывает строку, а вторая %*с отбрасывает перевод строки от текущего ввода*/
    scanf("%*c%[^\n]%*c", &data->note);
    return 1;
}

int ReadDateFromUser(struct entry *data)
{
    //Создание структуры, хранящей дату
    struct tm *datetime = malloc(sizeof(struct tm));
    memset(datetime, 0, sizeof(struct tm));
    
    //Считывание даты по частям
    int year, month, day, hour, minute;
    printf("\nВведите дату и время в формате ГГГГ ММ ДД чч мм: ");
    scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);
    //Время вычисляется начиная с 1900 года, так что нужно вычислить, сколько прошло лет с этого года
    datetime->tm_year = year - 1900;
    //Месяц вводится в удобном пользователю формате, а хранится в диапазоне от 0 до 11, так что его нужно преобразовать
    datetime->tm_mon = month - 1;
    datetime->tm_mday = day;
    datetime->tm_hour = hour;
    datetime->tm_min = minute;    
    
    //Исходя из даты вычисляется количество секунд, прошедших с начальной отметки
    data->timestamp = mktime(datetime);
    
    //Если дата неправильная, выход
    if(data->timestamp == -1)
    {
        printf("Некорректная дата.\n");
        return 0;
    }
    
    return 1;
}

void EditEntry()
{
    //Структура, хранящая заметку, которую нужно внести в ежедневник
    struct entry writedata;
    //Структура, хранящая заметки, считываемые из ежедневника для сравнения
    struct entry readdata;
    
    //Если данные введены неправильно, выход
    if(!ReadEntryFromUser(&writedata)) return;
    
    //Если записи не существует, ее нельзя изменить, выход
    if(!EntryExists(writedata.timestamp))
    {
        printf("Событие на заданное время не существует. Возвращаюсь в главное меню.\n");
        return;
    }
    
    //Открытие файла
    FILE *file = fopen(profile, "r+");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    //Считывание файла до нужной записи
    while(fread(&readdata, sizeof(struct entry), 1, file))
    {
        if(readdata.timestamp == writedata.timestamp) break;
    }
    //Смещение курсора назад, чтобы перезаписать заметку
    fseek(file, -sizeof(struct entry), SEEK_CUR);
    
    //Запись заметки
    fwrite(&writedata, sizeof(struct entry),1,file);
    
    fclose(file);
}

void DeleteEntry()
{
    //Структура, хранящая заметку, которую нужно удалить из ежедневника. Используется только время как ключ
    struct entry deletedata;
    //Структура, хранящая заметки, считываемые из ежедневника для сравнения
    struct entry readdata;
    
    //Если введена неправильная дата, выход
    if(!ReadDateFromUser(&deletedata)) return;
    
    //Если записи не существует, ее нельзя удалить, выход
    if(!EntryExists(deletedata.timestamp))
    {
        printf("Событие на заданное время не существует. Возвращаюсь в главное меню.\n");
        return;
    }
    
    //Открытие файла
    FILE *file = fopen(profile, "r");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    //Создание временного файла
    FILE *tempfile = fopen("temp", "w");
    if(tempfile == NULL)
    {
        printf("Не удалось создать временный файл.\n");
        exit(1);
    }
    
    //Запись всех заметок, кроме ненужной, во временный файл
    while(fread(&readdata, sizeof(struct entry), 1, file))
    {
        if(readdata.timestamp == deletedata.timestamp) continue;
        fwrite(&readdata, sizeof(struct entry), 1, tempfile);
    }

    fclose(file);
    fclose(tempfile);
    
    //Временный файл заменяет постоянный
    remove(profile);
    rename("temp", profile);
    remove("temp");
}

void DeleteOldEntries()
{
    //Структура, хранящая заметки, считываемые из ежедневника для сравнения
    struct entry readdata;
    
    //Открытие файла
    FILE *file = fopen(profile, "r");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }
    
    //Создание временного файла
    FILE *tempfile = fopen("temp", "w");
    if(tempfile == NULL)
    {
        printf("Не удалось создать временный файл.\n");
        exit(1);
    }
    
    //Сохранение текущего времени для определения, какие заметки считаются старыми
    time_t now;
    time(&now);
    
    //Запись всех заметок, кроме старых, во временный файл
    while(fread(&readdata, sizeof(struct entry), 1, file))
    {
        if(readdata.timestamp < now) continue;
        fwrite(&readdata, sizeof(struct entry), 1, tempfile);
    }

    fclose(file);
    fclose(tempfile);
    
    //Временный файл заменяет постоянный
    remove(profile);
    rename("temp", profile);
    remove("temp");
}