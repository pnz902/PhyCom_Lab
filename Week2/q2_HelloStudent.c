#include <stdio.h>

int main(){
	char name[20], surname[20], nickname[20], id[8];
    scanf("%s %s\n%s\n%s", name, surname, nickname, id);

    printf("Hello World, my name is %s (%s)\n", nickname, name);
    printf("\n");
    printf("Student ID: %s\n", id);
    printf("Name: %s %s\n", name, surname);
    printf("Nickname: %s", nickname);

	return 0;
}