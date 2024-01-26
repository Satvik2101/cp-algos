#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// kbx2157
using namespace std;

vector<bool> findPrimesTill(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }

        // we don't want to iterate over even numbers, so the for loop has i+=2;
        // but we start at i=2, so we minus 1 in the start
        // this way we iterate over 2,3,5,7,....
        if (i == 2)
            i--;
    }

    return isPrime;
}

int main() {
    vector<bool> primes = findPrimesTill(100);

    for (int i = 0; i < primes.size(); i++) {
        if (primes[i]) {
            cout << i << " ";
        }
    }

    return 0;
}