#include <stdio.h>

int main(){
	int num_int;
    float num_float;
    char c;

    scanf("%d\n%f\n%c", &num_int, &num_float, &c);

    printf("%.3f\n", (float) num_int);
    printf("%d\n", (int) num_float);
    printf("%d", (int) c);
    
	return 0;
}