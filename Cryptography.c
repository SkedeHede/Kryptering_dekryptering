#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Using ascii:
//A = 65..... Z = 90



#ifndef CEASER_SHIFT
#define CEASER_SHIFT 3
#endif

char *caeser_encrypt(char *plaintext);
char *caeser_decrypt(char *ciphertext);
char *vigenere_encrypt(char *plaintext, char *key);
char *vigenere_decrypt(char *ciphertext, char *key);


int main(void) {
    char mode[50];
    char cipher[50];
    char text[50];
    char key[50] = "";

    char line[256];


    while(1) {

        printf("Input mode, cipher and text as such: {mode} {cipher} {text} {key}\n");
        if (!fgets(line, sizeof line, stdin)) break;       //EOF
        line[strcspn(line, "\n")] = 0;                      //removes newline

        key[0] = '\0';                                      //empty key by default
        int got = sscanf(line, "%49s %49s %49s %49s", mode, cipher, text, key);

        if (got < 3) {                                      //checks for missing inputs
            puts("Need at least: mode, cipher, text");
            continue;
        }

        printf("you inputtet \"%s\" for mode, \"%s\" for cipher and \"%s\" for text and \"%s\" for key\n",
            mode, cipher, text, key);


        if (strcmp(mode, "e") == 0 || strcmp(mode, "encrypt") == 0) {
            if (strcmp(cipher, "c") == 0 || strcmp(cipher, "caeser") == 0) {
                printf("%s", caeser_encrypt(text));
            } else if (strcmp(cipher, "v") == 0 || strcmp(cipher, "vigenere") == 0) {
                printf("%s", vigenere_encrypt(text, key));
            } else {
                printf("Please enter a valid cryptography cipher: (c,v)/(caeser, vigenere)\n");
                continue;
            }
        } else if (strcmp(mode, "d") == 0 || strcmp(mode, "decrypt") == 0) {
            if (strcmp(cipher, "c") == 0 || strcmp(cipher, "caeser") == 0) {
                printf("%s", caeser_decrypt(text));
            } else if (strcmp(cipher, "v") == 0 || strcmp(cipher, "vigenere") == 0) {
                printf("%s", vigenere_decrypt(text, key));
            } else {
                printf("Please enter a valid cryptography cipher: (c,v)/(caeser, vigenere)\n");
                continue;
            }
        } else {
            printf("Please enter a valid cryptography mode: (e,d)/(encrypt, decrypt)\n");
            continue;
        }


        return 0;

    }

}


//definition of caeser encryption
char *caeser_encrypt(char *plaintext) {
    int n = strlen(plaintext);
    char *encrypted_text = malloc(n+1); //+1 til '\0'
    
    for(int i = 0; i < n; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            encrypted_text[i] = ((plaintext[i] - 'A' + CEASER_SHIFT) % 26) + 'A'; //converting with the assumption of only have capital letters
        } else {
            encrypted_text[i] = plaintext[i]; //if other symbols
        }
    }
    encrypted_text[n] = '\0'; //finishing the string

    return encrypted_text;
}

//definition of caeser decryption
char *caeser_decrypt(char *plaintext) {
    int n = strlen(plaintext);
    char *decrypted_text = malloc(n+1); //+1 til '\0'

    for(int i = 0; i < n; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            decrypted_text[i] = ((plaintext[i] - 'A' - CEASER_SHIFT) % 26) + 'A'; //converting with the assumption of only have capital letters
        } else {
            decrypted_text[i] = plaintext[i]; //if other symbols
        }
    }
    decrypted_text[n] = '\0'; //finishing the string

    return decrypted_text;
}

//definition of vigenere encryption
char *vigenere_encrypt(char *plaintext, char *key) {
    int n = strlen(plaintext);
    int m = strlen(key);
    char *encrypted_text = malloc(n+1); //+1 til '\0'

    for(int i = 0; i < n; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            encrypted_text[i] = ((plaintext[i] - 'A' + key[i % m] - 'A') % 26) + 'A'; //converting with the assumption of only have capital letters
        } else {
            encrypted_text[i] = plaintext[i];
        }
    }
    encrypted_text[n] = '\0';

    return encrypted_text;
}

//definition of vigenere decryption
char *vigenere_decrypt(char *plaintext, char *key) {
    int n = strlen(plaintext);
    int m = strlen(key);
    char *encrypted_text = malloc(n+1); //+1 til '\0'

    for(int i = 0; i < n; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            encrypted_text[i] = (((plaintext[i] - 'A') - (key[i % m] - 'A') + 26) % 26) + 'A'; //converting with the assumption of only have capital letters
        } else {
            encrypted_text[i] = plaintext[i];
        }
    }
    encrypted_text[n] = '\0';

    return encrypted_text;
}