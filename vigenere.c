#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool checkToDigital(char* keyword,const int keyLength){ //Checking digit in the key
    bool check;
    int n = keyLength;
    
    for (int i = 0; i < n; i++){
        check = false;
        
        if (!isalpha(keyword[i])){
            check = true;
            break;
        }
    }
    
    return check;
}

int* transformKey (char* keyword,const int keyLength){ //Transform text to key
    unsigned char c;
    int a = 97;
    int A = 65;
    int* k = (int*)malloc(keyLength*sizeof(int));
    int *p = k;
    
    for (int i = 0; i < strlen(keyword); i++){
        c = keyword[i];
        
        if (islower(c)){
            k[i] = keyword[i]-(a);
        } else if (isupper(c)){
            k[i] = keyword[i]-(A);
        } 
    } 
    return p;
}

void encrypt(int textIteration , char* text,int keyIteration, int* key){ //Encrypt char with help the key
    unsigned char c = text[textIteration];
    int k = key[keyIteration];
    int a = 97;
    int z = 122;
    int A = 65;
    int Z = 90;

    if (islower(c)){
        c = c + k;
        
        if (c > z){
            
            do {
                c = a + (c - z)-1;
            } while (c > z);
        }
    }  else if (isupper(c)){
        c = c + k;
        
        if (c > Z){
            
            do {
                c = A + (c - Z)-1;
            } while (c > Z);
        }
    }
    
    printf("%c", c);
}

void printText (char* text){ //Print array of char (for log)
        for (int i = 0; i < strlen(text); i++){
            printf("%c, ", text[i]);
        }
    printf("\n");
}

void printNumber(int* nubber, int length){ //Print array of int (for log)
    for (int i = 0; i < length; i++){
        printf("%i, ", nubber[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    
    if (argc == 2){
        char* keyword = argv[1];
        const int keyLength = strlen(keyword);        
        int* key;
        bool numberInKey; 
        
        if (keyword == 0) {
            return 1;
        }
        
        numberInKey = checkToDigital(keyword, keyLength);
        
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

        key = transformKey(keyword, keyLength);
        printf("ciphertext: ");

        for (int i = 0, j = 0, symbol = 0 ; i < textLength; i++){
            
            if (!isalpha(plaintext[i])){
                symbol++;
            }
            
            j = (i-symbol)%keyLength;
            encrypt(i , plaintext ,j , key);
        }
        
        printf("\n");
        
        printText(plaintext);
        printNumber(key, keyLength);
        
        free(key);
    } else {
        printf("Use key: ./vigenere <key>\n");
        return 1; 
    }
    
    return 0;
}