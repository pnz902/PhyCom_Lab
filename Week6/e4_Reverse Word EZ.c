#include <stdio.h>

int main(){
    char str[101];
    int null_terminator = 0;
    scanf("%[^\n]", str);

    for(int i=0; i<101; i++){
        if(str[i] == '\0'){
            null_terminator = i;
            break;
        }
    }

    for(int i=null_terminator-1; i>=0; i--){
        printf("%c", str[i]);
    }

    return 0;
}