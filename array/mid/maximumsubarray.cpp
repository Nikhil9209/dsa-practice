/*
    Problem: Maximum Subarray

    Topic: Array

    Pattern: Kadane's Algorithm

    Brute Force:
    Generate every possible subarray and calculate its sum.
    Keep track of the maximum sum.

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    Optimal Approach:
    Use Kadane's Algorithm.

    Maintain:
    curSum -> sum of the current subarray
    sum    -> maximum subarray sum found so far

    Add each element to curSum.

    If curSum becomes greater than sum:
    -> Update sum.

    If curSum becomes negative:
    -> Reset curSum to 0 because a negative sum
       will decrease the sum of any future subarray.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    If current subarray sum becomes negative,
    discard it and start a new subarray.

    Pattern:
    curSum += nums[i]

    curSum < 0 -> curSum = 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = INT_MIN;
        int curSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            curSum += nums[i];

            if (sum < curSum) {
                sum = curSum;
            }

            if (curSum < 0) {
                curSum = 0;
            }
        }

        return sum;
    }
};

int main() {
    return 0;
}