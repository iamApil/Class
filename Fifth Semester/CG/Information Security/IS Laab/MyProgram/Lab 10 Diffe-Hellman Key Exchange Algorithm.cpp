#include<stdio.h>
#include<math.h>

// Function to calculate power
long long int power(long long int a, long long int b, long long int P) {
    if (b == 1)
        return a;

    else
        return ((long long int)pow(a, b)) % P;
}

int main() {
    long long int P, G, x, a, y, b, ka, kb;

    // Publicly shared values
    printf("Enter the value of P (a prime number): ");
    scanf("%lld", &P);
    printf("Enter the value of G (a primitive root of P): ");
    scanf("%lld", &G);

    // Alice's private key
    printf("Enter the private key for Alice (a secret number): ");
    scanf("%lld", &a);

    // Bob's private key
    printf("Enter the private key for Bob (a secret number): ");
    scanf("%lld", &b);

    // Calculate public keys
    x = power(G, a, P); // Alice's public key
    y = power(G, b, P); // Bob's public key

    // Shared secret key computation
    ka = power(y, a, P); // Alice's shared secret key
    kb = power(x, b, P); // Bob's shared secret key

    printf("\nPublicly shared keys:\n");
    printf("Alice's Public Key: %lld\n", x);
    printf("Bob's Public Key: %lld\n", y);
    printf("\nSecret keys computed by Alice and Bob:\n");
    printf("Alice's Shared Secret Key: %lld\n", ka);
    printf("Bob's Shared Secret Key: %lld\n", kb);

    return 0;
}

