#include <stdio.h>
#include <string.h>

struct student_info{
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char id[13];
    float gpa;
};

int main(){
    struct student_info std;
    scanf("%s %s %s %d %s %f", std.name, std.surname, std.sex, &std.age, std.id, &std.gpa);

    if (strcmp(std.sex, "Male") == 0){
        printf("Mr ");
    } else {
        printf("Miss ");
    }

    printf("%c %s (%d) ", std.name[0], std.surname, std.age);
    printf("ID: %s GPA %.2f", std.id, std.gpa);

    return 0;
}