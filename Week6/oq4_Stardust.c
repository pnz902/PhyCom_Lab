#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int numCompare(const void *a, const void *b){
    return (*(double*)a - *(double*)b);
}

int main(){
    int n;
    scanf("%d", &n);

    double num[n];
    for (int i = 0; i < n; i++){
        scanf("%lf", &num[i]);
    }
    
    double avg = 0, median, std = 0;
    for (int i = 0; i < n; i++){
        avg += num[i]/n;
    }
    
    for (int i = 0; i < n; i++){
        std += pow(num[i]-avg, 2)/n;
    }

    std = sqrt(std);

    qsort(num, n, sizeof(num[0]), numCompare);
    
    int index = ceil(n/2.0);
    if (n%2 == 0){
        median = (num[index-1] + num[index])/2.0;
    } else{
        median = num[index-1];
    }

    printf("%.2lf\n", avg);
    printf("%.2lf\n", median);
    printf("%.2lf", std);


    return 0;
}