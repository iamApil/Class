#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Iterative Function to calculate (x^n)%p in O(logy) */
int power(int x, unsigned int n, int p) {
    int res = 1;     // Initialize result
    x = x % p; // Update 'x' if 'x' >= p like 24%23 becomes 1%23

    while (n > 0) {
        // If n is odd, multiply 'a' with result
        if (n%2==1)
            res = (res * x) % p;

        // n must be even now
        n = (int)(n/2);
        x = (x * x) % p;
    }
    return res;
    
}

/*Recursive function to calculate gcd of 2 numbers*/
int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

// If n is prime, then always returns true, If n is
// composite then returns false with high probability
// Higher value of k increases probability of correct
// result.
bool isPrime(unsigned int n, int k) {
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Try k times
    while (k > 0) {
        // Pick a random number in [2..n-2]    
        // Above corner cases make sure that n > 4
        int a = 2 + rand() % (n - 4);

        // Checking if a and n are co-prime
        if (gcd(n, a) != 1)
            return false;

        // Fermat's little theorem
        if (power(a, n - 1, n) != 1)
            return false;

        k--;
    }

    return true;
}

// Driver Program to test above function
int main() {
    int k,num; //check k times since this method is Probabilistic
    printf("Enter a Number to check its Primality: ");
    scanf("%d",&num);
    printf("\nEnter the number of times to check primality using Fermat's Little: ");
    scanf("%d",&k);
    printf("\nAccording to Fermat's Little Theorem: ");
    if (isPrime(num, k))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
    return 0;
}

