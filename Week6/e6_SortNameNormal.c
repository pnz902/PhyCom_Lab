#include <stdio.h>
#include <ctype.h>

int main(){
    char name[61], std[20][61], ch;
    int n;

    for (int i = 0; i < 20; i++)
    {
        scanf(" %60[^\n]", std[i]);
        int index = 0;
        while (std[i][index] != '\0')
        {
            if (index == 0 || std[i][index - 1] == ' ')
            {
                std[i][index] = toupper(std[i][index]);
            } else{
                std[i][index] = tolower(std[i][index]);
            }
            index++;
        }
    }

    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - i - 1; j++) {
            int k = 0;
            while (std[j][k] != '\0' && std[j][k] == std[j+1][k]) {
                k++;
            }
            
            if (std[j][k] > std[j + 1][k]) {
                int m = 0;
                while (std[j][m] != '\0' || std[j + 1][m] != '\0')
                {
                    char temp = std[j][m];
                    std[j][m] = std[j + 1][m];
                    std[j + 1][m] = temp;
                    m++;
                }
                std[j][m] = '\0';
                std[j+1][m] = '\0';
            }
        }
    }
    
    for (int i = 0; i < 20; i++)
    {
        printf("%s\n", std[i]);
    }

    return 0;
}