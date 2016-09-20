#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void encrypt(int i , string text, int key){
    unsigned char c = text[i];
    
    if (c >= 97 && c <= 122){
        c = c + key;
        
        if (c > 122){
            do {
            c = 97 + (c - 122)-1;
            } while (c > 122);
        }
    }  else if (c >= 65 && c <= 90){
        c = c + key;
        
        if (c > 90){
            c = 65 + (c - 90)-1;
        }
    }
    printf("%c", c);
}

int main(int argc, string argv[]){
    
    if (argc == 2){
        int key = atoi(argv[1]);
        
        if (key == 0) {
            return 1;
        }
        printf("plaintext: ");
        char* text = GetString();
        printf("ciphertext: ");
        
        for (int i = 0 ; i < strlen(text) ; i++){
            encrypt(i , text , key);
        }
        printf("\n");
    } else {
        printf("Use key: ./caesar <key>\n");
        return 1;
    }
    return 0;
}