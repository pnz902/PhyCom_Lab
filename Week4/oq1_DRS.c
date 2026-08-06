#include <stdio.h>

int main(){
    int safety, round, round_SafetyCar;
    float dif;

    scanf("%d\n%f\n%d\n%d", &safety, &dif, &round, &round_SafetyCar);

    int con1, con2, con3, con4;
    con1 = !safety;
    con2 = !(round > 2);
    con3 = !(round >= round_SafetyCar + 2);
    con4 = !(dif < 1);

    if (!(con1 + con2 + con3 + con4))
    {
        printf("DRS allowed");
    }
    else
    {
        printf("DRS not allowed %d", con1 + con2 + con3 + con4);
    }

    return 0 ;
}