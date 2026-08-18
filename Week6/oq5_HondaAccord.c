#include <stdio.h>

int main(){
    int n, now;
    char name[60];

    scanf("%[^\n]", name);
    scanf("%d", &n);
    int period[n];
    for (int i = 0; i < n; i++){
        scanf("%d ", &period[i]);
    }
    scanf("%d", &now);


    printf("%s\n", name);
    for(int i = 0; i < n-1; i++){
        if (now <= period[i+1] && now >= period[i]){
            printf("%d - %d", period[i], period[i+1]);
            return 0;
        }
    }

    printf("> %d", period[n-1]);

    return 0;
}