#include <stdio.h>

// Function to perform shift rows operation
void shiftRows(unsigned char state[][4]) {
    unsigned char temp;

    // Shift row 1 by 1 position to the left
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // Shift row 2 by 2 positions to the left
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // Shift row 3 by 3 positions to the left
    temp = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp;
}

// Function to perform shift columns operation
void shiftColumns(unsigned char state[][4]) {
    unsigned char temp;

    // Shift column 1
    temp = state[1][0];
    state[1][0] = state[2][0];
    state[2][0] = state[3][0];
    state[3][0] = temp;

    // Shift column 2
    temp = state[0][1];
    state[0][1] = state[1][1];
    state[1][1] = state[2][1];
    state[2][1] = state[3][1];
    state[3][1] = temp;

    // Shift column 3
    temp = state[0][2];
    state[0][2] = state[1][2];
    state[1][2] = temp;
    temp = state[2][2];
    state[2][2] = state[3][2];
    state[3][2] = temp;

    // Shift column 4
    temp = state[0][3];
    state[0][3] = state[3][3];
    state[3][3] = state[2][3];
    state[2][3] = state[1][3];
    state[1][3] = temp;
}

// Function to display the state matrix
void displayState(unsigned char state[][4]) {
    printf("State Matrix:\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%02X ", state[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Sample state matrix (4x4)
    unsigned char state[4][4] = {
        {0x32, 0x88, 0x31, 0xE0},
        {0x43, 0x5A, 0x31, 0x37},
        {0xF6, 0x30, 0x98, 0x07},
        {0xA8, 0x8D, 0xA2, 0x34}
    };

    // Display original state
    printf("Original State:\n");
    displayState(state);
    printf("\n");

    // Perform shift rows operation
    shiftRows(state);
    printf("After Shift Rows:\n");
    displayState(state);
    printf("\n");

    // Perform shift columns operation
    shiftColumns(state);
    printf("After Shift Columns:\n");
    displayState(state);

    return 0;
}

