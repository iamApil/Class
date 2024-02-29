#include <stdio.h>

// Function to calculate gcd (Greatest Common Divisor)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate Euler's totient function (phi)
int phi(int n) {
    int result = 1;
    for (int i = 2; i < n; ++i) {
        if (gcd(i, n) == 1)
            result++;
    }
    return result;
}

int main() {
    int num;

    printf("Enter a number to find its totient value: ");
    scanf("%d", &num);

    int totient = phi(num);
    printf("Euler's totient function (phi) of %d is: %d\n", num, totient);

    return 0;
}

