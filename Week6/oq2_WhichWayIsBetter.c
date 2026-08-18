#include <stdio.h>

int main(){
    double e20;
    int path[4], count_ex = 0, count_rom = 0;
    double expressway = 0, romklao = 0, fuel_price[4], liters[4], cost[4];

    scanf("%lf", &e20);
    scanf("%d %d %d %d", &path[0], &path[1], &path[2], &path[3]);
    scanf("%lf %lf %lf %lf", &fuel_price[0], &fuel_price[1], &fuel_price[2], &fuel_price[3]);
    for (int i=0; i<4; i++){
        if (path[i] == 0){
            liters[i] = 25/fuel_price[i];
            if (fuel_price[i] == 0) liters[i] = 0;
            cost[i] = liters[i]*e20;
            romklao += cost[i];
            count_rom++;
        } else{
            liters[i] = 29/fuel_price[i];
            if (fuel_price[i] == 0) liters[i] = 0;
            cost[i] = (liters[i]*e20)+60;
            expressway += cost[i];
            count_ex++;
        }
        printf("Day %d: fuel %.2lf L, cost %.2lf Baht\n", i+1, liters[i], cost[i]);
    }

    if (count_ex == 0) count_ex = 1;
    if (count_rom == 0) count_rom =1;
    printf("Expressway: %.2lf Baht\n", expressway/count_ex);
    printf("Romklao: %.2lf Baht", romklao/count_rom);

    return 0;
}