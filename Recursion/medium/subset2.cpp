/*
    Problem: Subsets II

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick + Duplicate Handling

    Brute Force:
    Generate all possible subsets and remove duplicate subsets.

    Since every element has two choices (pick or not pick),
    there can be up to 2^n subsets.

    Time Complexity: O(2^n * n)
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Optimal Approach:
    1. Sort the array so duplicate elements come together.
    2. Pick the current element and move to idx + 1.
    3. For the not-pick case, skip all elements having the same
       value as nums[idx].
    4. Continue recursion from the first different element.

    Example:
        nums = [1, 2, 2]

        When we don't pick the first 2, we skip the second 2
        as well to avoid generating duplicate subsets.

        But when we pick the first 2, we can still pick the
        second 2, so [2,2] remains possible.

    Time Complexity: O(2^n * n)
    Space Complexity: O(n)

    Key Learning:
    Sort first and skip duplicate choices only for the
    NOT-PICK branch.

    Revision Note:
    Pick → idx + 1
    Not Pick → skip duplicates → first different element
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void subset(int idx,
                vector<int>& nums,
                vector<int>& arr,
                vector<vector<int>>& ans) {

        // All elements processed
        if (idx >= nums.size()) {
            ans.push_back(arr);
            return;
        }

        // Pick
        arr.push_back(nums[idx]);

        subset(idx + 1, nums, arr, ans);

        // Backtrack
        arr.pop_back();

        // Not Pick
        for (int j = idx + 1; j < nums.size(); j++) {

            // Found the first different element
            if (nums[j] != nums[idx]) {
                subset(j, nums, arr, ans);
                return;
            }
        }

        // No different element found
        subset(nums.size(), nums, arr, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> arr;

        subset(0, nums, arr, ans);

        return ans;
    }
};

int main() {
    return 0;
}