#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    while (n != 0)
    {
        printf("%d ", n);
        if (n < 0) n++;
        else n--;
    }
    printf("0");

    return 0;
}