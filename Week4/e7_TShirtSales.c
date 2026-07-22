#include <stdio.h>
#include <math.h>

int main(){
    double price, discount;
    int n;

    scanf("%lf\n%lf\n%d", &price, &discount, &n);

    double pro_1 = n * price * (1 - discount/100);
    double pro_2 = (floor(n/3)*2 + n%3)*price;

    if (pro_1 <= pro_2)
    {
        printf("Discount %.0lf%%\n", discount);
        printf("%.2lf", pro_1);
    }
    else
    {
        printf("Buy 2 Get 1\n");
        printf("%.2lf", pro_2);
    }

    return 0 ;
}