#include <stdio.h>
#include <math.h>

double std(double x, double y){
    double c;
    c = sqrt((x*x)+(y*y));
    return c;
}

int main(){
    double x, y;
    scanf("%lf %lf", &x, &y);

    double c = std(x, y);
    printf("sqrt(%.0lf^2+%.0lf^2)=%.2lf", x, y, c);
    return 0;
}