#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int compareNames(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main(){
    int n;
    scanf("%d", &n);

    char name[n][61];
    
    for (int i = 0; i < n; i++){
        scanf(" %60[^\n]", name[i]);

        int index = 0;
        while(name[i][index] != '\0'){
            if(name[i][index - 1] == ' ' || index == 0){
                name[i][index] = toupper((unsigned char)name[i][index]);
            } else{
                name[i][index] = tolower((unsigned char)name[i][index]);
            }
            index++;
        }
    }

    qsort(name, n, sizeof(name[0]), compareNames);
    for (int i = 0; i < n; i++){
        printf("%s\n", name[i]);
    }

    return 0;
}