#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char* name = GetString();
    
    if (name[0] >= 97 && name[0] <= 122){
        printf("%c" , name[0]-32);
    } else {
        printf("%c" , name[0]);
    }
    
    for (int i = 0 , n = 0; i < strlen(name); i++){
        
        if (name[i] == 32){
            n = i + 1;
            
            if (name[n] >= 97 && name[n] <= 122){
                printf("%c" , name[n]-32);
            } else {
                printf("%c" , name[n]);
            }
        }
    }
    
    printf("\n");
}