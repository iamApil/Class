#include <stdio.h>
#include <string.h>

void createPlayfairMatrix(char key[], char matrix[5][5]);
void encryptPlayfair(char plaintext[], char key[], char ciphertext[]);
void decryptPlayfair(char ciphertext[], char key[], char plaintext[]);
void displayPlayfairMatrix(char matrix[5][5]);

int main() {
    char key[] = "KEYWORD";
    char plaintext[] = "DIPESHCODER";
    char ciphertext[100];
    char decryptedText[100];

    char matrix[5][5];
    createPlayfairMatrix(key, matrix);
    displayPlayfairMatrix(matrix);
    encryptPlayfair(plaintext, key, ciphertext);
    decryptPlayfair(ciphertext, key, decryptedText);

    printf("\nOriginal Text: %s\n", plaintext);
    printf("Encrypted Text: %s\n", ciphertext);
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}

void createPlayfairMatrix(char key[], char matrix[5][5]) {
    int len = strlen(key);
    int k = 0;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";  // Note: 'J' is skipped

    // Initialize matrix with zeros
    int i,j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            matrix[i][j] = 0;
        }
    }

    // Fill matrix with the key
    for (i = 0; i < len; i++) {
        char letter = key[i];

        // Check for duplicates and 'J' (replace with 'I')
        if (letter == 'J')
            letter = 'I';
        int found = 0,r,c;
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (matrix[r][c] == letter) {
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found) {
            matrix[k / 5][k % 5] = letter;
            k++;
        }
    }

    // Fill remaining matrix with the alphabet
    for (i = 0; i < 26; i++) {
        char letter = alphabet[i];

        // Check for duplicates and 'J' (replace with 'I')
        if (letter == 'J')
            letter = 'I';
        int found = 0,r,c;
        for (r = 0; r < 5; r++) {
            for ( c = 0; c < 5; c++) {
                if (matrix[r][c] == letter) {
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found) {
            matrix[k / 5][k % 5] = letter;
            k++;
        }
    }
}

void encryptPlayfair(char plaintext[], char key[], char ciphertext[]) {
    char matrix[5][5];
    createPlayfairMatrix(key, matrix);

    int len = strlen(plaintext);
    int i, j, i1, j1, i2, j2, t;

    int k = 0; // Index for ciphertext

    for (t = 0; t < len; t += 2) {
        char pair1 = plaintext[t];
        char pair2 = (t + 1 < len) ? plaintext[t + 1] : 'X'; // Append 'X' if needed
//		char pair1 = (plaintext[t] == 'J') ? 'I' : plaintext[t];
//        char pair2 = (t + 1 < len) ? ((plaintext[t + 1] == 'J') ? 'I' : plaintext[t + 1]) : 'X';


        if (pair1 == pair2) {
            pair2 = 'X'; // Replace repeated letters with 'X'
            t--; // Decrement t to process the current character again
        }

        // Display plaintext pair
        printf("Pair: %c%c -> ", pair1, pair2);

        // Find positions of the letters in the matrix
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (matrix[i][j] == pair1) {
                    i1 = i;
                    j1 = j;
                }
                if (matrix[i][j] == pair2) {
                    i2 = i;
                    j2 = j;
                }
            }
        }

        if (i1 == i2) {  // Same row
            ciphertext[k] = matrix[i1][(j1 + 1) % 5];
            ciphertext[k + 1] = matrix[i2][(j2 + 1) % 5];
        } else if (j1 == j2) {  // Same column
            ciphertext[k] = matrix[(i1 + 1) % 5][j1];
            ciphertext[k + 1] = matrix[(i2 + 1) % 5][j2];
        } else {  // Forming a rectangle
            ciphertext[k] = matrix[i1][j2];
            ciphertext[k + 1] = matrix[i2][j1];
        }
        k += 2;

        // Display encrypted pair
        printf("Encrypted Pair: %c%c\n", ciphertext[k - 2], ciphertext[k - 1]);
    }
    ciphertext[k] = '\0';
}

void decryptPlayfair(char ciphertext[], char key[], char plaintext[]) {
    char matrix[5][5];
    createPlayfairMatrix(key, matrix);

    int len = strlen(ciphertext);
    int i, j, i1, j1, i2, j2,t;

    int k = 0; // Index for plaintext

    for ( t = 0; t < len; t += 2) {
        char pair1 = ciphertext[t];
        char pair2 = ciphertext[t + 1];

        // Find positions of the letters in the matrix
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (matrix[i][j] == pair1) {
                    i1 = i;
                    j1 = j;
                }
                if (matrix[i][j] == pair2) {
                    i2 = i;
                    j2 = j;
                }
            }
        }

        if (i1 == i2) {  // Same row
            plaintext[k] = matrix[i1][(j1 - 1 + 5) % 5];
            plaintext[k + 1] = matrix[i2][(j2 - 1 + 5) % 5];
        } else if (j1 == j2) {  // Same column
            plaintext[k] = matrix[(i1 - 1 + 5) % 5][j1];
            plaintext[k + 1] = matrix[(i2 - 1 + 5) % 5][j2];
        } else {  // Forming a rectangle
            plaintext[k] = matrix[i1][j2];
            plaintext[k + 1] = matrix[i2][j1];
        }
        
        // Check for 'I' in plaintext and replace it with 'J' if necessary
//        if (plaintext[k] == 'I' && t + 2 < len && plaintext[t + 2] == plaintext[k + 1]) {
//            plaintext[k] = 'J';
//        } else if (plaintext[k + 1] == 'I' && t + 2 < len && plaintext[t + 2] == plaintext[k]) {
//            plaintext[k + 1] = 'J';
//        }

        k += 2;
    }

    // Remove any trailing 'X' if present
    if (plaintext[k - 1] == 'X') {
        plaintext[k - 1] = '\0';
    } else {
        plaintext[k] = '\0';
    }
}

void displayPlayfairMatrix(char matrix[5][5]){
	int i,j;
	printf("Playfair Matrix:\n");
    for ( i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
