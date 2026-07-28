#include <stdio.h>

int main(){
    int age;
    float h, w;

    int con1_count = 0; //age >= 20 && h >= 160
    int con2_count = 0; //age < 20 && (h <= 180 || w >= 60)
    int con3_count = 0; //age >= 30 && (w >= 40 && w <= 80)
    int con4_count = 0; //(age < 40 && w < 85 ) || h <= 200
    int sum_age = 0;
    float sum_h = 0, sum_w;

    for (int i = 0; i < 50; i++)
    {
        scanf("%d %f %f", &age, &h, &w);
        
        if (age >= 20 && h >= 160) con1_count++;
        if (age < 20 && (h <= 180 || w >= 60)) con2_count++;
        if (age >= 30 && (w >= 40 && w <= 80)) con3_count++;
        if (age < 40 && (w < 85 || h <= 200)) con4_count++;
        
        sum_age += age;
        sum_h += h;
        sum_w += w;
    }
    
    printf("Age >= 20 and Height >= 160: %d\n", con1_count);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", con2_count);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", con3_count);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", con4_count);
    printf("Average Age: %d\n", sum_age/50);
    printf("Average Height: %.2f\n", sum_h/50);
    printf("Average Weight: %.2f", sum_w/50);

    return 0;
}