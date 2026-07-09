#include <stdio.h>

int main() {
	char fname[30], sname[30], id[8];
    int d, m, y;
    float gpa;
	scanf("%s\n%s\n%s\n%d/%d/%d\n%f", fname, sname, id, &d, &m, &y, &gpa);
    printf("Fullname: %s %s\n", fname, sname);
    printf("ID: %s\n", id);
    printf("DOB: %02d-%02d-%d\n", d, m, y);
    printf("GPA: %.2f", gpa);

	return 0;
}