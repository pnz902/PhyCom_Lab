#include <stdio.h>
#include <math.h>

double perimeter(double x, double y);
double area(double x, double y);

int main(){
    double a, b;
    scanf("%lf\n%lf", &a, &b);

    double r_perimeter, r_area;
    r_perimeter = perimeter(a, b);
    r_area = area(a, b);
    printf("Perimeter: %.2lf\n", r_perimeter);
    printf("Area: %.2lf", r_area);

    return 0;
}

double perimeter(double x, double y){
    double z;
    z = sqrt((x*x)+(y*y));
    return x+y+z;
}

double area(double x, double y){
    return 0.5*x*y;
}