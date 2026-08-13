#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char t1[101], t2[101];
    scanf("%[^\n]", t1);
    scanf(" %[^\n]", t2);

    printf("*** Results ***\n");
    int index = 0;
    while(t1[index] != '\0'){
        if (islower(t1[index])){
            t1[index] = toupper(t1[index]);
        } else{
            t1[index] = tolower(t1[index]);
        }
        index++;
    }
    
    index = 0;
    while(t2[index] != '\0'){
        if (islower(t2[index])){
            t2[index] = toupper(t2[index]);
        } else{
            t2[index] = tolower(t2[index]);
        }
        index++;
    }
    
    printf("%s\n%s\n", t1, t2);
    printf("***************\n");
    index = 0;
    while(t1[index] != '\0'){
        t1[index] = tolower(t1[index]);
        index++;
    }
    
    index = 0;
    while(t2[index] != '\0'){
        t2[index] = tolower(t2[index]);
        index++;
    }

    int are_same = strcmp(t1, t2) == 0;
    if (are_same){
        printf("Both strings are the same.");
    } else{
        printf("Both strings are not the same.");
    }

    return 0;
}