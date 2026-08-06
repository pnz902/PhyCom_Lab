#include <stdio.h>

int main(){
    unsigned int num[5];
    int i;

    scanf("%u %u %u %u %u", &num[0], &num[1], &num[2], &num[3], &num[4]);
    scanf("%d", &i);

    printf("Value at index %d is %u", i, num[i]);

    return 0;
}