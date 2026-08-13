#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int n;
    char name[3][50];
    float sum[3]= {}, t1, t2, t3;
    float max[3];

    scanf("%d", &n);
    scanf("%s %s %s", name[0], name[1], name[2]);

    for (int i = 0; i < 3; i++)
    {
        if (name[i][0] == 'N') max[i] = 6.6;
        else max[i] = 5.5;
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf(" %f %f %f", &t1, &t2, &t3);
        sum[0]+=t1;
        sum[1]+=t2;
        sum[2]+=t3;
    }
    
    printf("%s: %.0f refills\n", name[0], ceil(sum[0]/max[0]));
    printf("%s: %.0f refills\n", name[1], ceil(sum[1]/max[1]));
    printf("%s: %.0f refills\n", name[2], ceil(sum[2]/max[2]));

    return 0;
}