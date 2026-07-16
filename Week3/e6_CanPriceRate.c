#include <stdio.h>

int main(){
	double price, d, h;
    scanf("%lf\n%lf\n%lf", &price, &d, &h);

    double r = d/2;
    double volume = h*3.14159265359*r*r;
    printf("Volume : %.2fml\n", volume);
    printf("Baht/ml : %.4f", price/volume);

	return 0;
}