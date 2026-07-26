#include <stdio.h>

int main(){
    int start, end, dif;
    scanf("%d %d", &start, &end);
    dif = end - start;
    if (dif < 0) dif*=(-1);
    
    double s_total, s_accel, s_cruise;
    s_total = dif*4;
    if (start == 1 || (end == 1 && start > 1)) s_total += 2;
    s_accel = 2.25;
    s_cruise = s_total - 2*s_accel;

    double t_accel, t_decel, t_cruise, t_total;
    t_decel = 3;
    t_accel = 3;
    t_cruise = s_cruise/1.5;
    t_total = t_accel + t_cruise + t_decel;

    printf("%.2lf", t_total);

    return 0 ;
}