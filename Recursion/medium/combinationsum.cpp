/*
    Problem: Combination Sum

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick with Repetition

    Brute Force:
    Generate all possible combinations and check whether their
    sum is equal to the target.

    Time Complexity: Exponential
    Space Complexity: O(target) for recursion stack
                      (excluding the output)

    Optimal Approach:
    Use Pick / Not Pick recursion.

    Pick:
        Include candidates[idx] in the current combination.
        Since an element can be used unlimited times, we call
        the recursion with the SAME index.

        combination(idx, target - candidates[idx], ...)

    Not Pick:
        Skip the current element and move to the next index.

        combination(idx + 1, target, ...)

    Base Cases:
        target == 0
            → Current combination is valid → store it.

        target < 0
            → Current combination exceeded target → return.

        idx >= candidates.size()
            → No elements left → return.

    Time Complexity: O(2^target) approximately
    Space Complexity: O(target) recursion depth
                      (excluding the output)

    Key Learning:
    If an element can be used multiple times:
        Pick → same index

    If an element cannot be reused:
        Pick → index + 1

    Revision Note:
    Pick → same index
    Not Pick → index + 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void combination(int idx,
                     vector<int>& candidates,
                     int target,
                     vector<vector<int>>& ans,
                     vector<int>& arr) {

        // Valid combination found
        if (target == 0) {
            ans.push_back(arr);
            return;
        }

        // Target exceeded
        if (target < 0)
            return;

        // No candidates left
        if (idx >= candidates.size())
            return;

        // Pick current element
        arr.push_back(candidates[idx]);

        combination(
            idx,
            candidates,
            target - candidates[idx],
            ans,
            arr
        );

        // Backtrack
        arr.pop_back();

        // Not Pick current element
        combination(
            idx + 1,
            candidates,
            target,
            ans,
            arr
        );
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target) {

        vector<int> arr;
        vector<vector<int>> ans;

        combination(0, candidates, target, ans, arr);

        return ans;
    }
};

int main() {
    return 0;
}