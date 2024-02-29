#include<iostream>
#include<cmath>
using namespace std;
// function to find GCD
int gcd(int a, int b) {
  while (true) {
    int remainder = a % b;
    if (remainder == 0) // b is a factor of a
      return b; // therefore, b is the gcd of a & b

    a = b;
    b = remainder;
  }
}

int main() {
  // 1. two prime numbers p & q are selected
  double p = 13;
  double q = 17;

  // 2. n is calculated
  double n = p * q;

  // 3. totient function value, phi, is calculated
  double phi = (p - 1) * (q - 1);

  // 4. a value e is selected such that is greater than 1 and
  //    is coprime to phi
  // we start searching from value 2
  double e = 2;

  while (e < phi) {
    double gcdOfEAndPhi = gcd(e, phi);
    // if gcd of e and phi is 1, then they are coprime
    if (gcdOfEAndPhi == 1) {
      break; // the desired value of e is found
    } else {
      e++; // keep the search for e on
    }
  }

  //5. value of d is calculated
  // d should satisfy the equation d = (1 / e) * mod(phi)  
  double eInverse = 1 / e;
  double d = fmod(eInverse, phi);

  // plaintext message
  double plainTextMessage = 97; // M = 97

  double encryptedMessage = pow(plainTextMessage, e);
  double decryptedMessage = pow(encryptedMessage, d);

  // 6. encrypting the plaintext message (M) to E
  encryptedMessage = fmod(encryptedMessage, n); // encryption complete

  // 7. decrypting the encrypted message (E) to get plaintext message (M)
  decryptedMessage = fmod(decryptedMessage, n); // decryption complete

  cout << "First prime number (p) = " << p << endl;
  cout << "Second prime number (q) = " << q << endl;
  cout << endl;

  cout << "Value of n = " << p * q << endl;
  cout << endl;

  cout << "Value of totient function, phi = " << phi << endl;
  cout << endl;

  cout << "Value of e = " << e << endl;
  cout << endl;

  cout << "Value of d = " << d << endl;
  cout << endl;

  cout << "Plain Text Message (M) = " << plainTextMessage << endl;
  cout << endl;

  cout << "Encrypted message (E) = " << encryptedMessage << endl;
  cout << "Decrypted message or Plaintext Message (M) = " << decryptedMessage << endl;
  // decrypted message and plaintext message are expected to be similar

  return 0;
}

