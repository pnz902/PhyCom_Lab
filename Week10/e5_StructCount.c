#include <stdio.h>
#include <ctype.h>

struct count{
    int characters;
    int word;
    int line;
};

int main(){
    struct count Count = {0, 0 ,0};
    char str[451];

    scanf("%[^\n]", str);
    while(str[0] != '.'){
        int index = 0;
        while(str[index] != '\0'){
            if (isalpha(str[index])){
                Count.characters++;
            } else if (str[index] == ' '){
                Count.word++;
            }
            index++;
        }
        Count.word++;
        Count.line++;
        scanf(" %[^\n]", str);
    }

    printf("Char = %d, word = %d, line = %d", Count.characters, Count.word, Count.line);

    return 0;
}