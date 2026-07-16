#include <stdio.h>

int main(){
	double width, length;
    scanf("%lf\n%lf", &width, &length);
    printf("Perimeter of rectangle = %.4lf units", (2*width) + (2*length));
    
	return 0;
}