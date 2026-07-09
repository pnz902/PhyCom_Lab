#include <stdio.h>

int main(){
	char name[200];
    scanf("%[^\n]", name);
    printf("Hello, %s!", name);
    
	return 0;
}