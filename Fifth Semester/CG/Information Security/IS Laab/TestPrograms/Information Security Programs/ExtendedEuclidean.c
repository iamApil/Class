#include <stdio.h>

// Function to calculate extended greatest common divisor (GCD) and Bézout coefficients
void extendedGCD(int a, int b, int *gcd, int *s2, int *t2) {
    int s1 = 1, t1 = 0;
    *s2 = 0, *t2 = 1;
    while (b != 0) {
        int quotient = a / b;
        int temp = b;
        b = a % b;
        a = temp;
        temp = *s2;
        *s2 = s1 - quotient * *s2;
        s1 = temp;
        temp = *t2;
        *t2 = t1 - quotient * *t2;
        t1 = temp;
    }
    *gcd = a;
    *s2 = s1;
    *t2 = t1;
}

int main() {
    int num1, num2, gcd, s, t;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    extendedGCD(num1, num2, &gcd, &s, &t);
    
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("Bézout coefficients: s = %d, t = %d\n", s, t);
    
    return 0;
}

