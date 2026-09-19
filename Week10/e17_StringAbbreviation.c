#include <stdio.h>
#include <ctype.h>

int main(){
    char name[201], surname[201];

    scanf("%s %s", name, surname);

    printf("%c.%c.", name[0], surname[0]);

    return 0;
}