#include <stdio.h>

int main(){
    float A[3][3], B[3][3], result[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &A[i][j]);
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &B[i][j]);
        }
    }
    
    for(int i = 0; i < 3; i++){
        float sum = 0;
        for(int j = 0; j < 3; j++){
            result[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j];
        }
        
    }

    printf("A x B\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}