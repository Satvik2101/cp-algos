#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// kbx2157
using namespace std;

// represents a solution for the equation ax+by=c
struct EquationSolution {
    int x = 0;
    int y = 0;
    int c = 0;

    bool solExists = true;
    void print(int a, int b) {
        if (!solExists) {
            cout << "No solution exists" << endl;
            return;
        }
        cout << a << " * " << x << " + " << b << " * " << y << " = " << c
             << endl;
        cout << a * x + b * y << " " << c;
    }
};

EquationSolution extendedEuclid(int a, int b) {
    EquationSolution sol;
    if (b == 0) {
        sol.x = 1;
        sol.y = 0;
        sol.c = a;
        return sol;
    }

    EquationSolution s = extendedEuclid(b, a % b);
    sol.x = s.y;
    sol.y = s.x - (a / b) * s.y;
    sol.c = s.c;
    return sol;
}

EquationSolution linearDipophantine(int a, int b, int c) {
    EquationSolution sol;
    sol.c = c;

    EquationSolution s = extendedEuclid(a, b);

    // s.c is gcd of a,b
    // s.x and s.y satisfy the equation (s.x)*a + (s.y)*b= gcd(a,b)
    cout << "GCD " << s.c << endl;

    // if c is divisible by gcd, only then does solution exist
    // if not (c%s.c will be non-zero), solution doesn't exist
    if (c % s.c) {
        sol.solExists = false;
        return sol;
    }
    sol.x = s.x * c / s.c;
    sol.y = s.y * c / s.c;

    if (a < 0)
        sol.x = -sol.x;
    if (b < 0)
        sol.y = -sol.y;

    return sol;
}
int main() {

    int a, b, c;
    cin >> a >> b >> c;
    EquationSolution s = linearDipophantine(a, b, c);
    s.print(a, b);
    // All solutions of the kind x = x+k*(b/gcd), y = y-k*(a/gcd) are valid,
    // where k is the iterator.
    return 0;
}