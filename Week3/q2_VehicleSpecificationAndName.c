#include <stdio.h>

int main(){
    char version[100];
    double power, w, price;
    scanf("%[^\n]", version);
    scanf("%lf\n%lf\n%lf", &power, &w, &price);
    printf("%.4lf\n%.4lf\n%.2lf\n%s", power, w, price, version);

    return 0 ;
}