// 8. By using key matrix Raju want to send message “we are discovered save
// yourself” to Rani. Can you build encryption process and find out what is the cipher
// text message send to Rani by using palyfaircipher.

#include <stdio.h>
#include <string.h>

void buildKeyMatrix(char key[], char keyMatrix[5][5]);

void findPosition(char keyMatrix[5][5], char ch, int *row, int *col);

void encryptPlayfair(char keyMatrix[5][5], char message[]);

int main() {
    char key[] = "srmapuniversity";
    char keyMatrix[5][5];
    char message[] = "wearediscoveredsaveyourself";

    buildKeyMatrix(key, keyMatrix);
    encryptPlayfair(keyMatrix, message);

    printf("Ciphertext: %s\n", message);

    return 0;
}

void buildKeyMatrix(char key[], char keyMatrix[5][5]) {
    int k = 0;
    int i, j;
    int keyLength = strlen(key);
    int isPresent[26] = {0};

    for (i = 0; i < keyLength; ++i) {
        if (key[i] != ' ' && isPresent[key[i] - 'a'] == 0) {
            keyMatrix[k / 5][k % 5] = key[i];
            isPresent[key[i] - 'a'] = 1;
            ++k;
        }
    }

    for (i = 0; i < 26; ++i) {
        if (isPresent[i] == 0) {
            keyMatrix[k / 5][k % 5] = 'a' + i;
            ++k;
        }
    }
}

void findPosition(char keyMatrix[5][5], char ch, int *row, int *col) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPlayfair(char keyMatrix[5][5], char message[]) {
    int len = strlen(message);

    for (int i = 0; i < len; i += 2) {
        if (message[i] == message[i + 1]) {
            len++;
            for (int j = len; j > i + 1; j--) {
                message[j] = message[j - 1];
            }
            message[i + 1] = 'x';
        }
    }

    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;

        findPosition(keyMatrix, message[i], &row1, &col1);
        findPosition(keyMatrix, message[i + 1], &row2, &col2);

        if (row1 == row2) {
            message[i] = keyMatrix[row1][(col1 + 1) % 5];
            message[i + 1] = keyMatrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            message[i] = keyMatrix[(row1 + 1) % 5][col1];
            message[i + 1] = keyMatrix[(row2 + 1) % 5][col2];
        } else {
            message[i] = keyMatrix[row1][col2];
            message[i + 1] = keyMatrix[row2][col1];
        }
    }
}
