#include <stdio.h>
#include <string.h>

struct Weather {
    char outlook[9]; //outlook{overcast,sunny,rain}
    int temperature;
    int humidity;
    char wind; //wind{T,F}
};

void playing_decision(struct Weather *w){
    int con_1 = strcmp(w->outlook, "overcast") == 0;
    int con_2 = strcmp(w->outlook, "rain") == 0 && (w->wind == 'F');
    int con_3 = strcmp(w->outlook, "sunny") == 0 && (w->humidity <= 78);

    if (con_1 + con_2 + con_3 > 0){
        printf("yes\n");
    } else {
        printf("no\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);

    struct Weather day[n];

    for (int i=0; i<n; i++){
        scanf(" %s %d %d %c", day[i].outlook, &day[i].temperature, &day[i].humidity, &day[i].wind);
    }

    for (int i=0; i<n; i++){
        playing_decision(&day[i]);
    }

    return 0;
}