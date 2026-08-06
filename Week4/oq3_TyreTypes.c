#include <stdio.h>

int main(){
    char type;

    scanf("%c", &type);

    switch (type)
    {
        case 's': case 'S':
            printf("Soft");
            break;
        case 'm': case 'M':
            printf("Medium");
            break;
        case 'h': case 'H':
            printf("Hard");
            break;
        case 'i': case 'I':
            printf("Intermediate");
            break;
        case 'w': case 'W':
            printf("Wet");
            break;
        default:
            break;
    }

    return 0;
}