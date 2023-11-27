#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// kbx2157
using namespace std;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {

    cout << power(2, 10) << endl;
    cout << power(2, 9) << endl << power(3, 0);
    return 0;
}