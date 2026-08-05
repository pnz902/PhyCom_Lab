#include <stdio.h>

int main(){
    int M[] = {2, 20, 8, 10, 4, 6, 16, 18};
    int N[] = {1, 3, 9, 7, 11, 15, 19};
    int num;

    while(1){
        scanf("%d", &num);
        if(num >= 1 && num <= 20){
            for(int i = 0; i < 8; i++){
                if(M[i] == num){
                    printf("%d is in M at index [%d]", num, i);
                    return 0;
                }
            }
    
            for(int i = 0; i < 7; i++){
                if(N[i] == num){
                    printf("%d is in N at index [%d]", num, i);
                    return 0;
                }
            }
    
            printf("%d is not in neither M nor N", num);
            return 0;
        }
    }

    return 0;
}