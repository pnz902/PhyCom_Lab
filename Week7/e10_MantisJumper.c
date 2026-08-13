#include <stdio.h>

long long fibo(long long floor){
    if (floor == 1) return 1;
    if (floor == 2) return 2;
    return fibo(floor - 1) + fibo(floor - 2);
}

int main(){
    long long floor, method;
    scanf("%lld", &floor);
    
    method = fibo(floor);
    printf("method = %lld", method);

    return 0;
}