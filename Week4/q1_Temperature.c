#include <stdio.h>

int main(){
    int celsius;
    scanf("%d", &celsius);

    double fahrenheit = (celsius * 9.0 / 5) + 32;
    
    printf("%.1lf\n", fahrenheit);

    return 0 ;
}