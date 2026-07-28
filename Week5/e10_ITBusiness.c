#include <stdio.h>

int main()
{
    float acc, cash, money;
    char action;
    int error = 0;

    scanf("%f\n%f", &acc, &cash);

    scanf("%c %f", &action, &money);
    while (!(action == 'E'))
    {
        switch (action)
        {
            case 'D':
                if (money <= cash)
                {
                    acc += money;
                    cash -= money;
                    error = 0;
                }
                else {
                    error++;
                }
                
                break;

            case 'W':
                if (money <= acc)
                {
                    cash += money;
                    acc -= money;
                    error = 0;
                }
                else {
                    error++;
                }
                break;

            default:
                break;
        }

        if (error >= 3) break;

        scanf("%c %f", &action, &money);
    }
    printf("%.2f\n%.2f", acc, cash);

    return 0;
}