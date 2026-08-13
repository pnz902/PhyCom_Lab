#include <stdio.h>

int main(){
    char text[101];
    int len = 0;
    scanf("%s", text);

    for (int i = 0; i < 101; i++)
    {
        if (text[i] == '\0')
        {
            len = i;
            break;
        }
        
    }

    for (int i = 0; i < len/2; i++)
    {
        if (text[i] != text[len-1-i])
        {
            printf("It is not Palindrome.");
            return 0;
        }
        
    }
    
    printf("It is Palindrome.");

    return 0;
}