#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

// Function to perform Caesar encryption
void caesarEncrypt(char *plaintext, int key) {
    while (*plaintext) {
        if (isalpha(*plaintext)) {
            char base = isupper(*plaintext) ? 'A' : 'a';
            *plaintext = ((int)(*plaintext - base + key) % 26) + base;
        }
        plaintext++;
    }
}

// Function to perform Caesar decryption
void caesarDecrypt(char *ciphertext, int key) {
    while (*ciphertext) {
        if (isalpha(*ciphertext)) {
            char base = isupper(*ciphertext) ? 'A' : 'a';
            *ciphertext = ((int)(*ciphertext - base - key + 26) % 26) + base;
        }
        ciphertext++;
    }
}

int main() {
    char message[1000];
    int key;

    // Get the message and key from the user
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key (a number between 0 and 25): ");
    scanf("%d", &key);

    // Remove newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Encrypt the message using Caesar cipher
    caesarEncrypt(message, key);
    printf("\nEncrypted Message: %s\n", message);

    // Decrypt the message using Caesar cipher
    caesarDecrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}

