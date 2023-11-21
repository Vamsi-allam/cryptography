/* Raju want to build encrypted and decryption algorithms of Playfair Cipher. Help
him to build a key matrix using the key “srmapuniversity”.*/

#include <stdio.h>
#include <string.h>
void generateKeyMatrix(char *key, char matrix[25]) {
  int keyLength = strlen(key);
  int matrixIndex = 0;
  int usedCharacters[26] = {0};

  for (int i = 0; i < keyLength; i++) {
    char currentChar = key[i];
    if (usedCharacters[currentChar - 'a'] == 0) {
      matrix[matrixIndex] = currentChar;
      usedCharacters[currentChar - 'a'] = 1;
      matrixIndex++;
    }
  }

  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (usedCharacters[ch - 'a'] == 0) {
      matrix[matrixIndex] = ch;
      usedCharacters[ch - 'a'] = 1;
      matrixIndex++;
    }
  }
}

int main() {
  char key[] = "srmapuniversity";
  char matrix[25];

  generateKeyMatrix(key, matrix);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%c ", matrix[i * 5 + j]);
    }
    printf("\n");
  }

  return 0;
}
