#include <stdio.h>

int main(){
    float A[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &A[i][j]);
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (A[i][j] != A[j][i] || (i != j && A[i][j] != 0))
            {
                printf("This is not a scalar matrix");
                return 0;
            }
        }
    }

    printf("This is a scalar matrix");

    return 0;
}