/*
    Problem: Count Subsequences With Target Sum

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick

    Brute Force:
    Generate all possible subsequences and count the subsequences
    whose sum is equal to k.

    For every element, we have two choices:
        1. Pick the element
        2. Not Pick the element

    Time Complexity: O(2^n)
    Space Complexity: O(n) for recursion stack

    Optimal Approach:
    Use Pick / Not Pick recursion.

    Pick:
        Move to the next index and subtract nums[idx]
        from the remaining target.

    Not Pick:
        Move to the next index without changing the target.

    Base Cases:
        tempsum == 0
            → Found one valid subsequence → return 1

        idx >= nums.size() || tempsum < 0
            → No valid subsequence → return 0

    Since we are counting all valid subsequences:
        answer = pick + notPick

    Time Complexity: O(2^n)
    Space Complexity: O(n)

    Key Learning:
    Existence problem → pick || notPick
    Counting problem  → pick + notPick

    Revision Note:
    Pick → target - nums[idx]
    Not Pick → target unchanged
    Count → add both branches
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count(int idx, vector<int>& nums, int tempsum) {

        if (tempsum == 0)
            return 1;

        if (idx >= nums.size() || tempsum < 0)
            return 0;

        // Pick
        int pick = count(
            idx + 1,
            nums,
            tempsum - nums[idx]
        );

        // Not Pick
        int notpick = count(
            idx + 1,
            nums,
            tempsum
        );

        return pick + notpick;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {

        return count(0, nums, k);
    }
};

int main() {
    return 0;
}