#include <stdio.h>
int main()
{
    int a, d, s=0;
    
    printf("    Здравствуйте!");
    
    do
    {
    
        printf("\n    На вашем счету сейчас %d рублей. Что вы хотите сделать?\n[1] Положить деньги на счёт\n[2] Снять деньги со счёта\n[3] Закрыть счёт\n\n",s);
        scanf("%d",&a);
        printf("\n");
    
        switch(a)
        {
            case 1:
                printf("Введите сумму: ");
                scanf("%d",&d);
                s+=d;
                printf("\nУ вас на счету %d рублей\n",s);
                break;
            
            case 2:
                printf("Введите сумму: ");
                scanf("%d",&d);
                if(s<d) printf("На счете отсутствуют средства"); 
                else
                {
                    s-=d;
                    printf("\nУ вас на счету %d рублей\n",s);
                }
                break;
        
            case 3:
                printf("Выход из счёта...");
                break;
        
            default:
                printf("\nНеправильно введена команда. Попробуйте ещё раз.");
                break;
        }
    }
    while (a!=3);
    return 0;
}
