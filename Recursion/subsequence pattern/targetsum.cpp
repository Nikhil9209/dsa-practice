/*
    Problem: Check Subsequence Sum

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick

    Brute Force:
    Generate all possible subsequences and check whether any
    subsequence has sum equal to k.

    For every element, there are two choices:
        1. Pick the element
        2. Do not pick the element

    Time Complexity: O(2^n)
    Space Complexity: O(n) for recursion stack

    Optimal Approach:
    Use recursion with Pick / Not Pick.

    Pick:
        Move to the next index and subtract nums[index]
        from the remaining target.

    Not Pick:
        Move to the next index without changing the target.

    Base Cases:
        tempSum == 0
            → A valid subsequence is found → return true

        index == n OR tempSum < 0
            → No valid subsequence → return false

    At every step:
        pick || notPick

    Time Complexity: O(2^n)
    Space Complexity: O(n)

    Key Learning:
    For an existence question, combine the two recursive
    branches using OR (||).

    Revision Note:
    Pick    → tempSum - nums[index]
    Not Pick → tempSum unchanged
    Existence → pick || notPick
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkSum(int index, int tempSum, vector<int>& nums) {

        // Valid subsequence found
        if (tempSum == 0) {
            return true;
        }

        // No elements left / target exceeded
        if (index >= nums.size() || tempSum < 0) {
            return false;
        }

        // Pick
        bool pick = checkSum(
            index + 1,
            tempSum - nums[index],
            nums
        );

        // Not Pick
        bool notPick = checkSum(
            index + 1,
            tempSum,
            nums
        );

        return pick || notPick;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {

        return checkSum(0, k, nums);
    }
};

int main() {
    return 0;
}