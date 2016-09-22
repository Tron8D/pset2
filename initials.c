#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){ //More Comfortable
    char* name = GetString();
    int space = 32;
    int firstLetter = 0;
    int* f = &firstLetter;
    
    if (name[*f] == space){
        do {
            *f+=1;
        } while (name[*f] == space);
    }       

    if (islower(name[*f])){
        printf("%c" , toupper(name[*f]));
    } else {
        printf("%c" , name[*f]);
    }
    
    for (int i = *f , n = 0; i < strlen(name); i++){
        
        if (name[i] == space){
            do {
                n = i + 1;
                i = n;
            } while (name[n] == space);
            
            if (name[n] == '\0'){
                break;    
            }
            
            if (islower(name[n])){
                printf("%c" , toupper(name[n]));
            } else {
                printf("%c" , name[n]);
            }
        }
    }
    printf("\n");
}