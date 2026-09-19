#include <stdio.h>
#include <string.h>


struct Book {
    char id[10];
    char name[100];
    char author[100];
};

int main(){
    int n;
    scanf("%d", &n);

    struct Book book[n];
    char find_id[10];
    scanf("%s", find_id);

    for (int i=0; i<n; i++){
        scanf(" %s %s %s", book[i].id, book[i].name, book[i].author);
    }

    for (int i=0; i<n; i++){
        if (strcmp(find_id, book[i].id) == 0){
            printf("%s %s %s", book[i].id, book[i].name, book[i].author);
            return 0;
        }
    }

    printf("Not Found");

    return 0;
}