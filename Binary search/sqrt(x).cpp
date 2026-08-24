/*
    Problem: Sqrt(x)

    Topic: Binary Search

    Pattern: Binary Search on Answer
    Optimal Approach:
    Use binary search to find the largest number
    whose square is less than or equal to x.

    If mid * mid == x:
    -> Exact square root found.

    If mid * mid < x:
    -> mid is a possible answer.
    -> Store mid and search on the right.

    If mid * mid > x:
    -> mid is too large.
    -> Search on the left.

    Time Complexity: O(log x)
    Space Complexity: O(1)

    Key Learning:
    Find the maximum value satisfying:
    mid * mid <= x

    mid² < x  -> possible answer -> move right
    mid² > x  -> too large -> move left
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        if (x < 2)
            return x;

        int low = 2;
        int high = x;
        int ans = 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if ((long long)mid * mid == x) {
                return mid;
            }

            else if ((long long)mid * mid > x) {
                high = mid - 1;
            }

            else {
                ans = mid;
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}