#include <stdio.h>
#include <ctype.h>

int main(){
    char find, text[151];

    scanf("%c", &find);
    scanf(" %[^\n]", text);

    int index = 0, count = 0;
    while(text[index] != '\0'){
        if (tolower(text[index]) == tolower(find)){
            count++;
        }
        index++;
    }

    printf("%d", count);

    return 0;
}