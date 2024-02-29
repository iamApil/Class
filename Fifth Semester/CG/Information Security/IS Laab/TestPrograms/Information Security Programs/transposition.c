#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Key for Columnar Transposition
const char key[] = "HACK";
int keyMap[256];

void setPermutationOrder() {
    // Add the permutation order into the keyMap array
    for (int i = 0; i < strlen(key); i++) {
        keyMap[(int)key[i]] = i;
    }
}

// Encryption
char* encryptMessage(const char* msg) {
    int row, col, j;
    static char cipher[1000]; // Assuming a fixed size buffer for simplicity
    
    // Calculate column of the matrix
    col = strlen(key);
    
    // Calculate maximum row of the matrix
    row = strlen(msg) / col;
    if (strlen(msg) % col)
        row += 1;

    char matrix[row][col];

    for (int i = 0, k = 0; i < row; i++) {
        for (int j = 0; j < col; ) {
            if (msg[k] == '\0') {
                // Adding the padding character '_'
                matrix[i][j] = '_';
                j++;
            }

            if (isalpha(msg[k]) || msg[k] == ' ') {
                // Adding only space and alphabet into matrix
                matrix[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }

    for (int l = 0; l < strlen(key); l++) {
        j = keyMap[(int)key[l]];

        // Getting cipher text from matrix column-wise using permuted key
        for (int i = 0; i < row; i++) {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
                sprintf(cipher + strlen(cipher), "%c", matrix[i][j]);
        }
    }

    return cipher;
}

// Decryption
char* decryptMessage(const char* cipher) {
    // Calculate row and column for cipher Matrix
    int col = strlen(key);
    int row = strlen(cipher) / col;
    char cipherMat[row][col];

    // Add characters into matrix column-wise
    for (int j = 0, k = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cipherMat[i][j] = cipher[k++];

    // Update the order of key for decryption
    int index = 0;
    for (int l = 0; key[l] != '\0'; l++)
        keyMap[(int)key[l]] = index++;

    // Arrange the matrix column-wise according
    // to permutation order by adding into a new matrix
    char decCipher[row][col];
    int k = 0;
    for (int l = 0, j; key[l] != '\0'; k++) {
        j = keyMap[(int)key[l++]];
        for (int i = 0; i < row; i++) {
            decCipher[i][k] = cipherMat[i][j];
        }
    }

    // Getting Message using the matrix
    static char msg[1000]; // Assuming a fixed size buffer for simplicity
    strcpy(msg, "");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (decCipher[i][j] != '_')
                sprintf(msg + strlen(msg), "%c", decCipher[i][j]);
        }
    }
    return msg;
}

// Driver Program
int main(void) {
    // Message
    const char* msg = "Geeks for Geeks";

    setPermutationOrder();

    // Calling encryption function
    const char* cipher = encryptMessage(msg);
    printf("Encrypted Message: %s\n", cipher);

    // Calling Decryption function
    printf("Decrypted Message: %s\n", decryptMessage(cipher));

    return 0;
}

