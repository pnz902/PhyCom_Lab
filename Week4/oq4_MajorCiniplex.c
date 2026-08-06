#include <stdio.h>

int main(){
    int age, day, price;

    scanf("%d\n%d", &age, &day);

    printf("Ticket price: ");
    if (day == 4)
    {
        price = 100;
    }
    else
    {
        if (age >= 60)
        {
            price = 140;
        }
        else if (age >= 13)
        {
            price = 220;
        }
        else
        {
            price = 120;
        }

        if (day == 1 || day == 7) price += 20;
    }
    
    printf("%d Baht", price);

    return 0;
}