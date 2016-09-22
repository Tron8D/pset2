#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
void encrypt(int i , string text, int key){ //Encrypt char with help the key
    unsigned char c = text[i];

    if (islower(c)){
        c = c + key;
        
        if (c > 'z'){
            do {
                c = 'a' + (c - 'z')-1;
            } while (c > 'z');
        }
    }  else if (isupper(c)){
        c = c + key;
        
        if (c > 'Z'){
            do {
                c = 'A' + (c - 'Z')-1;
            } while (c > 'Z');
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