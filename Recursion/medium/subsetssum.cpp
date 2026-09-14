/*
    Problem: Subset Sums

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick

    Brute Force:
    Generate all possible subsets and calculate the sum of every
    subset.

    Since every element has two choices (pick or not pick),
    there are 2^n possible subsets.

    Time Complexity: O(2^n)
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Optimal Approach:
    Use Pick / Not Pick recursion.

    At every index:

        1. Not Pick:
           Move to the next index without changing the sum.

        2. Pick:
           Add nums[idx] to the current sum and move to the
           next index.

    When idx reaches n, the current sum represents the sum of
    one complete subset, so add it to the answer.

    Time Complexity: O(2^n)
    Space Complexity: O(n)
                      (excluding the output)

    Key Learning:
    Every element has exactly two choices:

        Pick     → sum + nums[idx]
        Not Pick → sum unchanged

    Revision Note:
    Subset generation = Pick / Not Pick
    At the leaf → store the current sum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void sums(int idx,
              long long x,
              vector<int>& nums,
              vector<int>& ans) {

        // Complete subset formed
        if (idx >= nums.size()) {
            ans.push_back(x);
            return;
        }

        // Not Pick
        sums(idx + 1, x, nums, ans);

        // Pick
        x += nums[idx];

        sums(idx + 1, x, nums, ans);

        // Backtrack
        x -= nums[idx];
    }

    vector<int> subsetSums(vector<int>& nums) {

        vector<int> ans;

        sums(0, 0, nums, ans);

        return ans;
    }
};

int main() {
    return 0;
}