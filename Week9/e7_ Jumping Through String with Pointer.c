#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d\n%d", &n, &m);
    char* str = (char*) malloc(sizeof(char) * (n+1));
    scanf(" %[^\n]s", str);

    int c = 0;
    char *p = str;
    while(c <= n && *p != '\0'){
        printf("%c", *p);
        p+=m;
        c+=m;
    }

    free(str);

    return 0;
}