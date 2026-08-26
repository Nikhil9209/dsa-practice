/*
    Problem: Find the Smallest Divisor Given a Threshold

    Topic: Binary Search

    Pattern: Binary Search on Answer
    Use Binary Search on the divisor.

    Search Range:
    low = 1
    high = maximum element

    For a particular divisor:
    Calculate:
    ceil(nums[i] / divisor)

    If divisorSum <= threshold:
    -> Current divisor is possible.
    -> Try a smaller divisor.
    -> Move left.

    If divisorSum > threshold:
    -> Divisor is too small.
    -> Increase the divisor.
    -> Move right.

    Time Complexity: O(n * log(max(nums)))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Answer

    Divisor works:
    divisorSum <= threshold
    -> high = mid - 1

    Divisor does not work:
    divisorSum > threshold
    -> low = mid + 1

    Ceiling Division:
    (nums[i] + divisor - 1) / divisor
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxi(vector<int>& nums, int n) {

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    long long isDivisor(vector<int>& nums, int mid, int n) {

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += (nums[i] + (long long)mid - 1) / mid;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();

        int low = 1;
        int high = maxi(nums, n);
        int divisor = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long divisorSum = isDivisor(nums, mid, n);

            if (divisorSum <= threshold) {
                divisor = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return divisor;
    }
};

int main() {
    return 0;
}