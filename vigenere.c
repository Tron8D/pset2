#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool checkToDigital(char* keyword,const int KEY_LENGTH){ //Checking digit in the key
    bool check;

    for (int i = 0; i < KEY_LENGTH; i++){
        check = false;
        
        if (!isalpha(keyword[i])){
            check = true;
            break;
        }
    }
    return check;
}

int* transformKey (char* keyword,const int KEY_LENGTH){ //Transform text to key
    unsigned char c;
    int* k = (int*)malloc(KEY_LENGTH*sizeof(int));
    int *p = k;
    
    for (int i = 0; i < strlen(keyword); i++){
        c = keyword[i];
        
        if (islower(c)){
            k[i] = keyword[i]-('a');
        } else if (isupper(c)){
            k[i] = keyword[i]-('A');
        } 
    } 
    return p;
}

void encrypt(int textIteration , char* text,int keyIteration, int* key){ //Encrypt char with help the key
    unsigned char c = text[textIteration];
    int k = key[keyIteration];

    if (islower(c)){
        c = c + k;
        
        if (c > 'z'){
            do {
                c = 'a' + (c - 'z')-1;
            } while (c > 'z');
        }
    }  else if (isupper(c)){
        c = c + k;
        
        if (c > 'Z'){
            do {
                c = 'A' + (c - 'Z')-1;
            } while (c > 'Z');
        }
    }
    printf("%c", c);
}

void printText (char* text){ //Print array of char (for LOG)
        for (int i = 0; i < strlen(text); i++){
            printf("%c,", text[i]);
        }
    printf("\n");
}

void printNumber(int* nubber, int length){ //Print array of int (for LOG)
    for (int i = 0; i < length; i++){
        printf("%i,", nubber[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    if (argc == 2){
        char* keyword = argv[1];
        const int KEY_LENGTH = strlen(keyword);        
        int* key;
        bool numberInKey; 
        
        if (keyword == 0) {
            return 1;
        }
        
        numberInKey = checkToDigital(keyword, KEY_LENGTH);
        
        if (numberInKey){
            printf("Use alphabetic key: ./vigenere <key>\n");
            return 1;
        }
        
        printf("plaintext: ");
        char* plaintext = GetString();
        const int textLength = strlen(plaintext);
        
        if (textLength < 1){
            printf("Need plaintext!\n");
            return 1;
        }

        key = transformKey(keyword, KEY_LENGTH);
        printf("ciphertext: ");

        for (int i = 0, j = 0, symbol = 0 ; i < textLength; i++){
            
            if (!isalpha(plaintext[i])){
                symbol++;
            }
            
            j = (i-symbol)%KEY_LENGTH;
            encrypt(i , plaintext ,j , key);
        }
        
        printf("\n");
/*For LOG:  
        printText(plaintext);
        printNumber(key, KEY_LENGTH);
*/
        free(key);
    } else {
        printf("Use key: ./vigenere <key>\n");
        return 1; 
    }
    return 0;
}