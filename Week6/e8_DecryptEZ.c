#include <stdio.h>
#include <ctype.h>

int main(){
    char text[201];
    char l_en[] = "iwgzvfuthsojlkdecnmrqpyxba";
    scanf("%[^\n]", text);

    for (int i = 0; i < 201; i++)
    {
        if (text[i] == '\0') break;
        
        if (text[i] != ' ')
        {
            for (int j = 0; j < 27; j++)
            {
                if (tolower(text[i]) == l_en[j])
                {
                    int dc_index = j-5;
                    if (dc_index < 0) dc_index = 26 + dc_index;

                    if (islower(text[i])) printf("%c", l_en[dc_index]);
                    else printf("%c", toupper(l_en[dc_index]));
                }
            }
        } else{
            printf(" ");
        }
    }

    return 0;
}