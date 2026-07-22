#include <stdio.h>

int main(){
    double distance;
    scanf("%lf", &distance);

    if (distance >= 0 && distance <= 58.855)
    {
        if (distance > 52.900)
        {
            printf("Chon Buri");
        }
        else if (distance > 35.477)
        {
            printf("Chachoengsao");
        }
        else if (distance > 5.032)
        {
            printf("Samut Prakarn");
        }
        else
        {
            printf("Bangkok");
        }
    }
    else
    {
        printf("InValid");
    }

    return 0 ;
}