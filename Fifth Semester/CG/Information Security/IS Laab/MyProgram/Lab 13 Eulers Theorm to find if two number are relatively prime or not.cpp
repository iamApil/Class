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

// Function to check if two numbers are relatively prime using Euler's theorem
int areRelativelyPrime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (areRelativelyPrime(num1, num2))
        printf("%d and %d are relatively prime.\n", num1, num2);
    else
        printf("%d and %d are not relatively prime.\n", num1, num2);

    return 0;
}

