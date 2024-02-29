#include <stdio.h>

#define NB 4  // Number of columns in the state array

// Function to perform the Shift Rows operation
void shiftRows(unsigned char state[NB][NB]) {
    unsigned char temp;

    // Shift second row by 1 position to the left
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // Shift third row by 2 positions to the left
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // Shift fourth row by 3 positions to the left
    temp = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp;
}

// Function to print the state array
void printState(unsigned char state[NB][NB]) {
	int i,j;
    for ( i = 0; i < NB; i++) {
        for ( j = 0; j < NB; j++) {
            printf("%02X ", state[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    unsigned char state[NB][NB] = {
        {0x00, 0x01, 0x02, 0x03},
        {0x04, 0x05, 0x06, 0x07},
        {0x08, 0x09, 0x0A, 0x0B},
        {0x0C, 0x0D, 0x0E, 0x0F}
    };

    printf("Original state:\n");
    printState(state);

    shiftRows(state);

    printf("\nState after Shift Rows operation:\n");
    printState(state);

    return 0;
}

