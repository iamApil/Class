#include <stdio.h>
#include <ctype.h>
#include <string.h>

char mod26(char c) {
  return (c - 'A') % 26 + 'A';
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
  int i, j, key_len = strlen(key), plaintext_len = strlen(plaintext);

  for (i = 0, j = 0; i < plaintext_len; i++, j = (j + 1) % key_len) {
    if (!isalpha(plaintext[i])) {
      ciphertext[i] = plaintext[i];
      continue;
    }
    ciphertext[i] = mod26(plaintext[i] - 'A' + toupper(key[j]) - 'A');
  }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
  int i, j, key_len = strlen(key), ciphertext_len = strlen(ciphertext);

  for (i = 0, j = 0; i < ciphertext_len; i++, j = (j + 1) % key_len) {
    if (!isalpha(ciphertext[i])) {
      plaintext[i] = ciphertext[i];
      continue;
    }
    plaintext[i] = mod26(ciphertext[i] - 'A' - toupper(key[j]) + 'A');
  }
}

int main() {
  char plaintext[100], key[100], ciphertext[100];
  int choice;

  printf("1. Encrypt\n2. Decrypt\n");
  scanf("%d", &choice);

  printf("Enter plaintext: ");
  scanf(" %[^\n]", plaintext);

  printf("Enter key: ");
  scanf(" %[^\n]", key);

  switch (choice) {
    case 1:
      encrypt(plaintext, key, ciphertext);
      printf("Ciphertext: %s\n", ciphertext);
      break;
    case 2:
      decrypt(ciphertext, key, plaintext);
      printf("Plaintext: %s\n", plaintext);
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}

