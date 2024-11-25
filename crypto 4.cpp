#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char plaintext[], char key[], char ciphertext[]) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    int j = 0; 
    for (int i = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) { 
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char baseKey = isupper(key[j % keyLength]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + (key[j % keyLength] - baseKey)) % 26 + base;
            j++; 
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[textLength] = '\0'; 
}

int main() {
    char plaintext[100], key[100], ciphertext[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
