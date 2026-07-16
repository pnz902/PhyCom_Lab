#include <stdio.h>

int main(){
    int sec;
    scanf("%d", &sec);
    printf("%d s = %d d %d h %d m %d s", sec, sec/86400, sec%86400/3600, sec%3600/60, sec%60);

	return 0;
}