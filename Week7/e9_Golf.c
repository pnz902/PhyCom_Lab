#include <stdio.h>
#include <math.h>

int main(){
    double degree, u, h;
    scanf("%lf\n%lf", &degree, &u);

    double radius = (degree * 3.141592653589793)/180;
    h = (u*u*sin(radius)*sin(radius))/(2*9.81);
    printf("theta (degree) : %.0lf\n", degree);
    printf("u (m/s) : %.0lf\n", u);
    printf("h (m) : %.4lf", h);

    return 0;
}