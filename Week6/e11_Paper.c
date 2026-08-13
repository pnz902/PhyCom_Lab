#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char x[4], y[4];

    scanf("%s\n%s", x, y);

    int n_x = atoi(&x[1]);
    int n_y = atoi(&y[1]);

    printf("%.0f", pow(2.0, n_y-n_x));

    return 0;
}