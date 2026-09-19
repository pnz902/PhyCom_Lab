#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char text[151];
    scanf("%[^\n]", text);

    int index = 0, n = 1;
    while(text[index] != '\0'){
        if (text[index] == ' '){
            n++;
        }
        index++;
    }
    
    index = 0;
    char all_word[151][151];
    for (int i=0; i<n; i++){
        int len = 0;
        while(text[index] != '\0'){
            if (text[index] == ' '){
                index++;
                break;
            }
            all_word[i][len] = tolower(text[index]);
            len++;
            index++;
        }
    }


    printf("%d words\n", n);
    printf("----\n");
    for (int i=0; i<n; i++){
        printf("%s : %d\n", all_word[i], strlen(all_word[i]));
    }

    return 0;
}