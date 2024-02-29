#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to perform monoalphabetic encryption
void monoalphabeticEncrypt(char *plaintext, char *key) {
    while (*plaintext) {
        if (isalpha(*plaintext)) {
            char base = isupper(*plaintext) ? 'A' : 'a';
            *plaintext = key[*plaintext - base];
        }
        plaintext++;
    }
}

// Function to perform monoalphabetic decryption
void monoalphabeticDecrypt(char *ciphertext, char *key) {
    char *temp = (char *)malloc(26 * sizeof(char));
    int i;

    // Create the reverse key for decryption
    for (i = 0; i < 26; i++) {
        temp[key[i] - 'A'] = 'A' + i;
    }

    while (*ciphertext) {
        if (isalpha(*ciphertext)) {
            char base = isupper(*ciphertext) ? 'A' : 'a';
            *ciphertext = temp[*ciphertext - base];
        }
        ciphertext++;
    }

    free(temp);
}

int main() {
    char message[1000];
    char key[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; // Predefined key for encryption and decryption

    // Get the message from the user
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Encrypt the message using monoalphabetic cipher
    monoalphabeticEncrypt(message, key);
    printf("\nEncrypted Message: %s\n", message);

    // Decrypt the message using monoalphabetic cipher
    monoalphabeticDecrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}

