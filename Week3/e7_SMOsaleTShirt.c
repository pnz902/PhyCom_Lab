#include <stdio.h>

int main(){
    double old_price, discount;
    int n;
    scanf("%lf\n%lf\n%d", &old_price, &discount, &n);
    printf("%.2lf", old_price*(1-discount/100)*n);

	return 0;
}