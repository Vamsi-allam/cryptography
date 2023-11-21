// Raju send encrypted message “ZICVTWQNGKZEIIGASXSTSLVVWLA” to Rani. Can you build decryption process and find out what is the message send to Rani. Hint: try all keys for each character.

#include <stdio.h>
#include <string.h>

char *encrypt(char *plaintext, char *key) {
  int plaintext_length = strlen(plaintext);
  int key_length = strlen(key);
  char *ciphertext = malloc(plaintext_length + 1);

  for (int i = 0; i < plaintext_length; i++) {
    int plaintext_index = plaintext[i] - 'A';
    int key_index = key[i % key_length] - 'A';
    int ciphertext_index = (plaintext_index + key_index) % 26;
    ciphertext[i] = ciphertext_index + 'A';
  }

  ciphertext[plaintext_length] = '\0';
  return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {
  int ciphertext_length = strlen(ciphertext);
  int key_length = strlen(key);
  char *plaintext = malloc(ciphertext_length + 1);

  for (int i = 0; i < ciphertext_length; i++) {
    int ciphertext_index = ciphertext[i] - 'A';
    int key_index = key[i % key_length] - 'A';
    int plaintext_index = (ciphertext_index - key_index + 26) % 26;
    plaintext[i] = plaintext_index + 'A';
  }

  plaintext[ciphertext_length] = '\0';
  return plaintext;
}

int main() {
  char *plaintext = "WEAREDISCOVEREDSAVEYOURSELF";
  char *key = "DECEPTIVEWEAREDISCOVEREDSAV";

  char *ciphertext = encrypt(plaintext, key);
  printf("Ciphertext: %s\n", ciphertext);

  char *decrypted_plaintext = decrypt(ciphertext, key);
  printf("Plaintext: %s\n", decrypted_plaintext);

  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}
