#include <stdio.h>
#include <string.h>

struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
};

int main(){
    int n;
    scanf("%d", &n);

    struct Record emp[n];
    for (int i=0; i<n; i++){
        scanf(" %s %s %ld %ld", emp[i].id, emp[i].name, &emp[i].salary, &emp[i].sales);
    }

    char find_id[10];
    scanf("%s", find_id);

    for (int i=0; i<n; i++){
        if (strcmp(find_id, emp[i].id) == 0){
            double comm = 0.02*emp[i].sales;
            printf("%s\n%s\n%ld\n%.2lf\n%ld\n%.2lf", emp[i].id, emp[i].name, emp[i].sales, comm, emp[i].salary, emp[i].salary+comm);
            return 0;
        }
    }

    printf("ID not found !!!");

    return 0;
}