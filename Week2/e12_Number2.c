#include <stdio.h>

int main(){
    char num[5];
    scanf("%s", &num);
    
    printf("%.1s", num);
    printf("%79.0s", num);

    printf("%3.2s", num);
    printf("%77.0s", num);

    printf("%5.3s", num);
    printf("%75.0s", num);

    printf("%7.4s", num);
    printf("%73.0s", num);

    printf("%9s", num);

    return 0;
}