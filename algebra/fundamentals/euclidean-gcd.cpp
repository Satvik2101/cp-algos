#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// kbx2157
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void printGcd(int a, int b) {
    cout << a << " " << b << "->" << gcd(a, b) << endl;
}

int main() {
    printGcd(3, 4);
    printGcd(15, 20);
    printGcd(4, 0);
    printGcd(1, 2);
    printGcd(2, 100);
    printGcd(37, 111);
    printGcd(37, 197);
    return 0;
}