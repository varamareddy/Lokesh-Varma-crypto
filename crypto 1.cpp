#include <stdio.h>
#include <ctype.h>
#include <string.h>
void caesarCipher(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isupper(ch)) {
            text[i] = ((ch - 'A' + shift) % 26) + 'A';
        }
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + shift) % 26) + 'a';
        }
    }
}

int main() {
    char text[100];
    int shift;
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }
}
