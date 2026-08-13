#include <stdio.h>

int main(){
    char str[101];
    int n;

    scanf("%[^\n]", str);
    scanf("%d", &n);

    printf("%.*s", n, str);

    return 0;
}