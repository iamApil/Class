#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt plaintext using Rail Fence technique
void encryptRailFence(char *plaintext, int rails, char *ciphertext) {
    int len = strlen(plaintext);
    int i, j, k = 0;
    char railFence[rails][len];

    // Initialize railFence matrix with placeholder character '#'
    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            railFence[i][j] = '#';
        }
    }

    // Fill the railFence matrix with characters from plaintext
    i = 0;
    j = 0;
    int down = 1;
    while (k < len) {
        railFence[i][j] = plaintext[k++];
        if (down) {
            if (i == rails - 1) {
                down = 0;
                i--;
            } else {
                i++;
            }
        } else {
            if (i == 0) {
                down = 1;
                i++;
            } else {
                i--;
            }
        }
        j++;
    }

    // Construct ciphertext by reading railFence matrix row-wise
    k = 0;
    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            if (railFence[i][j] != '#') {
                ciphertext[k++] = railFence[i][j];
            }
        }
    }
    ciphertext[k] = '\0';
}

// Function to decrypt ciphertext using Rail Fence technique
void decryptRailFence(char *ciphertext, int rails, char *decryptedtext) {
    int len = strlen(ciphertext);
    int rail_lengths[rails];
    int i, j, k = 0;

    // Calculate lengths of each rail
    for (i = 0; i < rails; i++) {
        rail_lengths[i] = (len + rails - 1 - i) / rails;
    }

    // Initialize decryptedtext with placeholder character '#'
    for (i = 0; i < len; i++) {
        decryptedtext[i] = '#';
    }

    // Fill decryptedtext with characters from ciphertext
    i = 0;
    j = 0;
    for (i = 0; i < rails; i++) {
        k = i;
        for (j = 0; j < rail_lengths[i]; j++) {
            decryptedtext[k] = ciphertext[i * (rail_lengths[0] - 1) + j];
            k += rails;
        }
    }
    decryptedtext[len] = '\0';
}

int main() {
    char plaintext[1000], ciphertext[1000], decryptedtext[1000];
    int rails;

    // Get plaintext and number of rails from the user
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    // Encrypt the plaintext using Rail Fence technique
    encryptRailFence(plaintext, rails, ciphertext);
    printf("\nEncrypted Text: %s\n", ciphertext);

    // Decrypt the ciphertext using Rail Fence technique
    decryptRailFence(ciphertext, rails, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}

