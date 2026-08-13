#include <stdio.h>
#include <ctype.h>

int main(){
    char text[301], find;
    int len, count = 0;
    scanf("%[^\n]", text);
    scanf("\n%c", &find);
    for (int i = 0; i < 301; i++)
    {
        if (text[i] == '\0')
        {
            len = i;
            break;
        }
        
    }

    int position[len], index = 0;
    for (int i = 0; i < len; i++)
    {
        if (find == tolower(text[i])){
            count++;
            position[index] = i;
            index++;
        }
    }
    

    if (count)
    {
        printf("There is/are %d \"%c\" in the above sentences.\n", count, find);
        printf("Position: ");
        printf("%d", position[0]+1);
        for (int i = 1; i < index; i++)
        {
            printf(", %d", position[i]+1);
        }
        
    }else{
        printf("Not found.");
    }
    
    return 0;
}