/*
    Problem: Count Good Numbers

    Topic: Recursion / Maths

    Pattern: Binary Exponentiation (Fast Power)

    Brute Force:
    Generate all possible n-digit numbers and check whether
    each digit satisfies the condition.
    This takes O(10^n), which is too slow.

    Optimal Approach:
    Even positions have 5 possible digits: {0, 2, 4, 6, 8}.
    Odd positions have 4 possible digits: {2, 3, 5, 7}.

    Therefore:
        Answer = 5^(number of even positions)
                 * 4^(number of odd positions)

    To calculate the powers efficiently, use Binary Exponentiation:
    - If power is even, square the base and divide power by 2.
    - If power is odd, multiply the base once and reduce power by 1.

    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion

    Key Learning:
    Large power → Binary Exponentiation.
    Even positions → 5 choices.
    Odd positions → 4 choices.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long power(long long n, long long pow) {

        if(pow == 0) {
            return 1;
        }

        if(pow % 2 == 0) {
            return power((n * n) % 1000000007, pow / 2);
        }

        return (n * power(n, pow - 1)) % 1000000007;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans1 = power(5, even);
        long long ans2 = power(4, odd);

        return (ans1 * ans2) % 1000000007;
    }
};

int main() {
    return 0;
}