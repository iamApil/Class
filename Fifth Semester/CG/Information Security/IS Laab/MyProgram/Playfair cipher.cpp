#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key_square[5][5];
char message[100];
int message_length;

void build_key_square(char *key) {
    int i, j, key_index = 0;
    char used_chars[26] = {0};

    // Fill with key characters, removing duplicates
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (key_index < strlen(key)) {
                char c = toupper(key[key_index]);
                if (c == 'J') {
                    c = 'I'; // Replace J with I to avoid confusion
                }
                if (!used_chars[c - 'A']) {
                    key_square[i][j] = c;
                    used_chars[c - 'A'] = 1;
                } else {
                    key_index++;
                }
            } else {
                key_square[i][j] = 'X' + key_index - strlen(key);
            }
            key_index++;
        }
    }
}

void split_digraphs(char *digraphs) {
    int i = 0;

    while (message[i] != '\0') {
        if (i % 2 == 1 && message[i] == message[i - 1]) {
            // Handle repeated letters by inserting 'X'
            digraphs[2 * i] = message[i - 1];
            digraphs[2 * i + 1] = 'X';
        } else {
            digraphs[2 * i] = message[i];
            digraphs[2 * i + 1] = message[i + 1];
        }
        i += 2;
    }
    digraphs[2 * i] = '\0'; // Null terminate
}

void find_coordinates(char c1, char c2, int *row1, int *col1, int *row2, int *col2) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (key_square[i][j] == c1) {
                *row1 = i;
                *col1 = j;
            }
            if (key_square[i][j] == c2) {
                *row2 = i;
                *col2 = j;
            }
        }
    }
}

void encrypt_digraph(char c1, char c2, char *ciphertext) {
    int row1, col1, row2, col2;

    find_coordinates(c1, c2, &row1, &col1, &row2, &col2);

    if (row1 == row2) {
        // Same row, shift right circularly
        ciphertext[0] = key_square[row1][(col1 + 1) % 5];
        ciphertext[1] = key_square[row1][(col2 + 1) % 5];
    } else if (col1 == col2) {
        // Same column, shift down circularly
        ciphertext[0] = key_square[(row1 + 1) % 5][col1];
        ciphertext[1] = key_square[(row2 + 1) % 5][col2];
    } else {
        // Swap positions diagonally
        ciphertext[0] = key_square[row1][col2];
        ciphertext[1] = key_square[row2][col1];
    }
}

void decrypt_digraph(char c1, char c2, char *plaintext) {
    int row1, col1, row2, col2;

    find_coordinates(c1, c2, &row1, &col1, &row2, &col2);

    if (row1 == row2) {
        // Same row, shift left circularly
        plaintext[0] = key_square[row1][(col1 - 1 + 5) % 

