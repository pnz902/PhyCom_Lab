#include <stdio.h>
#include <ctype.h>

int main(){
    int n;
    char alpha[26] = {};
    int count[26] = {};
    char temp;
    int point = 0;


    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &temp);

        int exist = 0;
        for (int i = 0; i < point; i++)
        {
            if (tolower(temp) == alpha[i])
            {
                exist = 1;
                count[i]++;
            }
        }
        
        if (!exist && tolower(temp) >= 'a' && tolower(temp) <= 'z')
        {
            alpha[point] = tolower(temp);
            count[point]++;
            point++;
        }
        
    }
    
    for (int i = 0; i < point; i++)
    {
        printf("%c: %d\n", alpha[i], count[i]);
    }

    return 0;
}