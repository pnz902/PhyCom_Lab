#include <stdio.h>

int main(){
    float height, weight;
    scanf("%f\n%f", &height, &weight);

    height *= 0.01;
    printf("%f", weight/(height*height));

	return 0;
}