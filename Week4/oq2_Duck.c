#include <stdio.h>

int main(){
    int quacks;

    scanf("%d", &quacks);

    if (quacks > 50)
    {
        printf("Duck Type: Talkative Duck");
    }
    else if (quacks >= 11)
    {
        printf("Duck Type: Happy Duck");
    }
    else if (quacks >= 1)
    {
        printf("Duck Type: Chill Duck");
    }
    else if (quacks == 0)
    {
        printf("Duck Type: Silent Duck");
    }
    else
    {
        printf("Error");
    }
    
    

    return 0;
}