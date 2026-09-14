/*
    Problem: Combination Sum II

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick + Duplicate Handling

    Brute Force:
    Generate all possible subsets of the array and check which
    subsets have sum equal to target.

    Since every element can be used at most once, each element
    has two choices:
        1. Pick
        2. Not Pick

    Time Complexity: O(2^n)
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Optimal Approach:
    1. Sort the array.
       This brings duplicate elements together.

    2. Pick the current element:
       Move to idx + 1 because each element can be used only once.

    3. Skip duplicate elements at the same recursion level
       to avoid generating duplicate combinations.

    4. Backtrack after picking an element.

    Important Difference from Combination Sum I:

        Combination Sum I:
            Pick → same index
            Element can be reused.

        Combination Sum II:
            Pick → idx + 1
            Element can be used only once.

    Time Complexity: O(2^n * n) approximately
    Space Complexity: O(n) recursion depth
                      (excluding the output)

    Key Learning:
    Sort first + skip duplicates at the same recursion level.

    Revision Note:
    Combination Sum I  → Pick same index
    Combination Sum II → Pick idx + 1
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

        if (target == 0) {
            ans.push_back(arr);
            return;
        }

        if (idx >= candidates.size() || target < 0)
            return;

        // Pick current element
        arr.push_back(candidates[idx]);

        combination(
            idx + 1,
            candidates,
            target - candidates[idx],
            ans,
            arr
        );

        // Backtrack
        arr.pop_back();

        // Not Pick current element
        for (int j = idx + 1; j < candidates.size(); j++) {

            if (candidates[idx] != candidates[j]) {
                return combination(
                    j,
                    candidates,
                    target,
                    ans,
                    arr
                );
            }
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> arr;
        vector<vector<int>> ans;

        combination(0, candidates, target, ans, arr);

        return ans;
    }
};

int main() {
    return 0;
}