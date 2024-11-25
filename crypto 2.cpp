#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabeticCipher(char plaintext[], char key[]) {
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        char ch = plaintext[i];
        if (isupper(ch)) {
            plaintext[i] = key[ch - 'A'];
        }
        else if (islower(ch)) {
            plaintext[i] = tolower(key[ch - 'a']);
        }
    }
}

int main() {
    char plaintext[100];
    printf("Enter text to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}
