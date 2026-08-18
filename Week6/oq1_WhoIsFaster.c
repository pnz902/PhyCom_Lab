#include <stdio.h>

int main(){
    char car_1[51], car_2[51];
    int time_1[7], time_2[7], sum_1, sum_2, equal = 0, c1 = 0, c2 = 0;

    scanf("%[^\n]", car_1);
    scanf(" %d %d %d %d %d %d %d", &time_1[0], &time_1[1], &time_1[2], &time_1[3], &time_1[4], &time_1[5], &time_1[6]);
    scanf(" %[^\n]", car_2);
    scanf(" %d %d %d %d %d %d %d", &time_2[0], &time_2[1], &time_2[2], &time_2[3], &time_2[4], &time_2[5], &time_2[6]);
    sum_1 = time_1[0]+time_1[1]+time_1[2]+time_1[3]+time_1[4]+time_1[5]+time_1[6];
    sum_2 = time_2[0]+time_2[1]+time_2[2]+time_2[3]+time_2[4]+time_2[5]+time_2[6];

    for (int i = 0; i < 7; i++){
        if (time_1[i] < time_2[i]){
            c1++;
        } else if (time_1[i] == time_2[i]){
            equal++;
        } else{
            c2++;
        }

    }

    printf("%s: %d minutes, average %d minutes/day\n", car_1, sum_1, sum_1/7);
    printf("%s: %d minutes, average %d minutes/day\n", car_2, sum_2, sum_2/7);
    printf("Faster days - %s: %d, %s: %d, Equal: %d", car_1, c1, car_2, c2, equal);

    return 0;
}