/*
    Problem: Power Set / Subsets

    Topic: Recursion / Backtracking

    Pattern: Include / Exclude

    Brute Force:
    Generate all possible subsets by considering every possible
    combination of elements.

    For each element, there are two choices:
        1. Exclude the element
        2. Include the element

    Since there are n elements and each has 2 choices:
        Total subsets = 2^n

    Time Complexity: O(2^n * n)
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Optimal Approach:
    Use recursion with two choices at every index.

    At each index:
        - First, don't include nums[ind]
        - Then, include nums[ind]

    When ind == n, the current subset is complete,
    so add it to the answer.

    Backtracking:
        push_back() → include the element
        recursive call
        pop_back() → remove it before exploring the next choice

    Time Complexity: O(2^n * n)
    Space Complexity: O(n)

    Key Learning:
    Every element has exactly two choices:
        Include → Exclude

    Revision Note:
    Pick / Not Pick pattern.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void rec(int ind, int n, vector<int>& nums,
             vector<int>& arr, vector<vector<int>>& ans) {

        // Base case
        if (ind == n) {
            ans.push_back(arr);
            return;
        }

        // Exclude current element
        rec(ind + 1, n, nums, arr, ans);

        // Include current element
        arr.push_back(nums[ind]);

        rec(ind + 1, n, nums, arr, ans);

        // Backtrack
        arr.pop_back();
    }

    vector<vector<int>> powerSet(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> arr;

        rec(0, nums.size(), nums, arr, ans);

        return ans;
    }
};

int main() {
    return 0;
}