#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int used[26] = {0};
    int i, j, k = 0;
    for (i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            char ch = toupper(key[i]);
            if (ch == 'J') ch = 'I';
            if (!used[ch - 'A']) {
                keyMatrix[k / SIZE][k % SIZE] = ch;
                used[ch - 'A'] = 1;
                k++;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (i + 'A' != 'J' && !used[i]) {
            keyMatrix[k / SIZE][k % SIZE] = i + 'A';
            k++;
        }
    }
}
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptDigraph(char digraph[2], char keyMatrix[SIZE][SIZE]) {
    int row1, col1, row2, col2;
    findPosition(keyMatrix, digraph[0], &row1, &col1);
    findPosition(keyMatrix, digraph[1], &row2, &col2);

    if (row1 == row2) {
        digraph[0] = keyMatrix[row1][(col1 + 1) % SIZE];
        digraph[1] = keyMatrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        digraph[0] = keyMatrix[(row1 + 1) % SIZE][col1];
        digraph[1] = keyMatrix[(row2 + 1) % SIZE][col2];
    } else {
        digraph[0] = keyMatrix[row1][col2];
        digraph[1] = keyMatrix[row2][col1];
    }
}
void encryptText(char plaintext[], char keyMatrix[SIZE][SIZE], char ciphertext[]) {
    int len = strlen(plaintext);
    char digraph[2];
    int k = 0;

    for (int i = 0; i < len; i++) {
        digraph[0] = toupper(plaintext[i]);
        if (digraph[0] == 'J') digraph[0] = 'I';
		        if (i + 1 < len && toupper(plaintext[i + 1]) != digraph[0]) {
            digraph[1] = toupper(plaintext[++i]);
        } else {
            digraph[1] = 'X';
        }
        encryptDigraph(digraph, keyMatrix);
        ciphertext[k++] = digraph[0];
        ciphertext[k++] = digraph[1];
    }
    ciphertext[k] = '\0'; 
}

int main() {
    char key[100], plaintext[100], ciphertext[100];
    char keyMatrix[SIZE][SIZE];
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    prepareKeyMatrix(key, keyMatrix);
    encryptText(plaintext, keyMatrix, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
