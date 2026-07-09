#include <stdio.h>

int main(){
	int num_int;
    float num_float;
    char c;
    char str[20];

    scanf("%d", &num_int);
    scanf("%f", &num_float);
    scanf("\n%c", &c);
    scanf("%s", str);

    printf("Integer: %d\n", num_int);
    printf("Float: %.3f\n", num_float);
    printf("Character: %c\n", c);
    printf("String: %s", str);
    
	return 0;
}