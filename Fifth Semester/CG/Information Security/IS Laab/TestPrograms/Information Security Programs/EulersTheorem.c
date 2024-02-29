#include <stdio.h>

// Function to calculate greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate Euler's totient function
int phi(int n) {
    int result = 1,i;
    for ( i = 2; i < n; ++i) {
        if (gcd(i, n) == 1) {
            ++result;
        }
    }
    return result;
}

// Function to implement Euler's theorem
int eulersTheorem(int a, int n) {
    int phi_n = phi(n);
    int result = 1,i;
    for ( i = 0; i < phi_n; ++i) {
        result = (result * a) % n;
    }
    return result;
}

int main() {
    int a, n;
    printf("Enter two numbers (a and n): ");
    scanf("%d %d", &a, &n);
    printf("phi(%d) = %d\n",n,phi(n));
    if (gcd(a, n) == 1) {
        int result = eulersTheorem(a, n);
        printf("%d^%d is congruent to %d modulo %d.\n", a, phi(n), result, n);
    } else {
        printf("The numbers a and n are not relatively prime.\n");
    }

    return 0;
}

