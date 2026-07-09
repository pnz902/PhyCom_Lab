#include <stdio.h>

int main() {
	char fname1[20], sname1[20], person2[50], person3[50];
	scanf("%s\n%s\n%s  \n%s", fname1, sname1, person2, person3);
	printf("Person 1: %s %s\n", fname1, sname1);
	printf("Person 2: %s\n", person2);
	printf("Person 3: %s", person3);

	return 0;
}