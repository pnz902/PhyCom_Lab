#include <stdio.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    int mid_a = (a >= b && a <= c) || (a >= c && a <= b);
    int mid_b = (b >= a && b <= c) || (b >= c && b <= a);
    int mid_c = (c >= a && c <= b) || (c >= b && c <= a);

    if (mid_a)
    {
        printf("%.2lf", a);
    }
    else if (mid_b)
    {
        printf("%.2lf", b);
    }
    else
    {
        printf("%.2lf", c);
    }


    return 0 ;
}