#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// kbx2157
using namespace std;

// represents a solution for the equation ax+by=gcd(a,b)
struct ExtendedEuclidSolution {
    int x;
    int y;
    int gcd;

    void print(int a, int b) {
        cout << a << " * " << x << " + " << b << " * " << y << " = " << gcd
             << endl;
        cout << a * x + b * y << " " << gcd;
    }
};

ExtendedEuclidSolution extendedEuclid(int a, int b) {
    ExtendedEuclidSolution sol;
    if (b == 0) {
        sol.x = 1;
        sol.y = 0;
        sol.gcd = a;
        return sol;
    }

    ExtendedEuclidSolution s = extendedEuclid(b, a % b);
    sol.x = s.y;
    sol.y = s.x - (a / b) * s.y;
    sol.gcd = s.gcd;
    return sol;
}

int main() {

    int a, b;
    cin >> a >> b;
    ExtendedEuclidSolution s = extendedEuclid(a, b);
    s.print(a, b);
    return 0;
}