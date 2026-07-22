#include <stdio.h>
#include <ctype.h>

int main(){
    char input;
    scanf("%c", &input);

    if (isalnum(input))
    {

        if (islower(input))
        {
            printf("lowercase");
        }
        else if (isupper(input))
        {
            printf("uppercase");
        }
        else
        {
            printf("number");
        }
    }
    else
    {
        printf("error");
    }

    return 0 ;
}