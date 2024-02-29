#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to encrypt a message using Rail Fence Cipher
char* encryptRailFence(const char* text, int key) {
    int len = strlen(text),i,j;
    char rail[key][len];
    
    // Filling the rail matrix to distinguish filled spaces from blank ones
    for ( i = 0; i < key; i++) {
        for ( j = 0; j < len; j++) {
            rail[i][j] = '\n';
        }
    }

    bool dir_down = false;
    int row = 0, col = 0;

    for ( i = 0; i < len; i++) {
        if (row == 0 || row == key - 1) {
            dir_down = !dir_down;
        }
        rail[row][col++] = text[i];
        dir_down ? row++ : row--;
    }

    // Now construct the cipher using the rail matrix
    char* result = malloc(len + 1);
    int index = 0;

    for ( i = 0; i < key; i++) {
        for ( j = 0; j < len; j++) {
            if (rail[i][j] != '\n') {
                result[index++] = rail[i][j];
            }
        }
    }
    result[len] = '\0';
    return result;
}

// Function to decrypt a message using Rail Fence Cipher
char* decryptRailFence(const char* cipher, int key) {
    int len = strlen(cipher),i,j;
    char rail[key][len];

    // Filling the rail matrix to mark places with '*'
    for ( i = 0; i < key; i++) {
        for ( j = 0; j < len; j++) {
            rail[i][j] = '\n';
        }
    }

    bool dir_down;
    int row = 0, col = 0;

    for ( i = 0; i < len; i++) {
        if (row == 0) {
            dir_down = true;
        }
        if (row == key - 1) {
            dir_down = false;
        }
        rail[row][col++] = '*';
        dir_down ? row++ : row--;
    }

    // Fill the rail matrix
    int index = 0;
    for ( i = 0; i < key; i++) {
        for ( j = 0; j < len; j++) {
            if (rail[i][j] == '*' && index < len) {
                rail[i][j] = cipher[index++];
            }
        }
    }

    // Construct the resultant text
    char* result = malloc(len + 1);
    row = 0, col = 0;

    for ( i = 0; i < len; i++) {
        if (row == 0) {
            dir_down = true;
        }
        if (row == key - 1) {
            dir_down = false;
        }
        if (rail[row][col] != '*') {
            result[i] = rail[row][col++];
        }
        dir_down ? row++ : row--;
    }
    result[len] = '\0';
    return result;
}

// Driver program
int main() {
	const char* plain_text1 = "my name is dipesh ghimire";
	const char* plain_text2 = "i will complete my undergraduate degree next year";
	const char* plain_text3 = "i want to work as a freelancer";
	int key1=2,key2=3,key3=4;
	
    const char* cipher_text1 =encryptRailFence(plain_text1, key1);
    const char* cipher_text2 =encryptRailFence(plain_text2, key2);
    const char* cipher_text3 =encryptRailFence(plain_text3, key3);

    // Decryption of the same cipher-text
    const char* decrypted_text1 = decryptRailFence(cipher_text1, key1);
	const char* decrypted_text2 = decryptRailFence(cipher_text2, key2);
    const char* decrypted_text3 = decryptRailFence(cipher_text3, key3);
    
    printf("\n| Key | \t\tPlain Text\t\t | \t\tEncrypted Cipher Text\t\t | \t\tDecrypted Plain Text\t\t |\n");
    printf("|%d | %s\t\t\t | %s \t\t\t| %s|\n",key1,plain_text1,cipher_text1,decrypted_text1);
    printf("|%d | %s | %s\t | %s|\n",key2,plain_text2,cipher_text2,decrypted_text2);
    printf("|%d | %s\t\t | %s\t\t | %s|",key3,plain_text3,cipher_text3,decrypted_text3);
    return 0;
}

