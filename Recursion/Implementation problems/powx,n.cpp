/*
    Problem: Pow(x, n)

    Topic: Recursion / Binary Exponentiation

    Pattern: Fast Exponentiation (Exponentiation by Squaring)

    Brute Force:
    Multiply x by itself n times.

    Example:
        x^5 = x * x * x * x * x

    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion

    Optimal Approach:
    Use the fact that:

        x^n = (x^(n/2))^2        if n is even
        x^n = x * x^(n-1)        if n is odd

    For even n:
        pow(x, n) = pow(x*x, n/2)

    For odd n:
        pow(x, n) = x * pow(x, n-1)

    If n is negative:
        x^n = (1/x)^(-n)

    Convert n to long long first so that INT_MIN can be
    safely negated.

    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion

    Key Learning:
    Instead of reducing the exponent by 1 every time,
    reduce it by half whenever it is even.

    Revision Note:
    Even → x*x, n/2
    Odd  → x * pow(x,n-1)
    Negative n → x = 1/x, n = -n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    double pow(double x, long long n) {

        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return pow(x * x, n / 2);

        return x * pow(x, n - 1);
    }

    double myPow(double x, int n) {

        long long nn = n;

        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }

        return pow(x, nn);
    }
};

int main() {
    return 0;
}