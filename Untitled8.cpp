#include <iostream>
using namespace std;

bool isPrime(int n, int i = 2) {
    if (n <= 2) return (n == 2);
    if (n % i == 0) return false;
    if (i * i > n) return true;
    return isPrime(n, i + 1);
}

void generatePrimes(int n, int current = 2) {
    if (current > n) return;
    if (isPrime(current)) cout << current << " ";
    generatePrimes(n, current + 1);
}

int main() {
    int n = 20;
    cout << "Prime numbers up to " << n << ": ";
    generatePrimes(n);
    return 0;
}
