#include <stdio.h>

int main(){
    float t2, t3;
    char n1[50], n2[50], n3[50];
    float fastest;
    int n_fastest;

    scanf("%f %[^\n]",&fastest,n1);
    n_fastest = 1;

    scanf("%f %[^\n]",&t2,n2);
    if (t2 < fastest){
        fastest = t2;
        n_fastest = 2;
    }

    scanf("%f %[^\n]",&t3,n3);
    if (t3 < fastest){
        fastest = t3;
        n_fastest = 3;
    }

    if (n_fastest == 1){
        printf("%s ",n1);
    }else if (n_fastest == 2){
        printf("%s ",n2);
    }else{
        printf("%s ",n3);
    }
    printf("is Fastest : %.3f", fastest);

    return 0;
}