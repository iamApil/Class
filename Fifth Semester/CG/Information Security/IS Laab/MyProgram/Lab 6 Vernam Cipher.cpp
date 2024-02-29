#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Vernam encryption
void vernamEncrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    int len = strlen(plaintext);

    for (i = 0; i < len; ++i) {
        // XOR each character of plaintext with corresponding character of key
        ciphertext[i] = plaintext[i] ^ key[i];
    }
    ciphertext[i] = '\0';
}

// Function to perform Vernam decryption
void vernamDecrypt(char *ciphertext, char *key, char *decryptedtext) {
    int i;
    int len = strlen(ciphertext);

    for (i = 0; i < len; ++i) {
        // XOR each character of ciphertext with corresponding character of key
        decryptedtext[i] = ciphertext[i] ^ key[i];
    }
    decryptedtext[i] = '\0';
}

int main() {
    char plaintext[1000], key[1000], ciphertext[1000], decryptedtext[1000];

    // Get plaintext and key from the user
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    // Perform Vernam encryption
    vernamEncrypt(plaintext, key, ciphertext);
    printf("\nEncrypted Text: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02X", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    // Perform Vernam decryption
    vernamDecrypt(ciphertext, key, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}

