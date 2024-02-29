// C program to demonstrate Basic Euclidean Algorithm
#include <stdio.h>

// Function to return gcd of a and b
int gcd(int a, int b)
{	int temp;
	while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Driver code
int main()
{
	int num1,num2;
	printf("Enter any 2 numbers : ");
	scanf("%d%d",&num1,&num2);
	// Function call
	printf("GCD(%d, %d) = %d\n", num1, num2, gcd(num1, num2));
	return 0;
}

