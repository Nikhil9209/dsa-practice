/*
    Problem: Combination Sum III

    Topic: Recursion / Backtracking

    Pattern: Pick / Not Pick

    Brute Force:
    Generate all possible combinations of numbers from 1 to 9
    and check whether:
        1. Exactly k numbers are selected.
        2. Their sum is equal to n.

    Time Complexity: O(2^9) ≈ O(1)
    Space Complexity: O(k) recursion stack
                      (excluding the output)

    Optimal Approach:
    Use Pick / Not Pick recursion.

    At every number from 1 to 9:

        Pick:
            Add the current number to the combination.
            Increase count by 1.
            Decrease the remaining sum.

        Not Pick:
            Skip the current number and move to the next number.

    Base Case:
        If remaining sum == 0 AND count == k,
        we found a valid combination.

    Pruning:
        - If remaining sum becomes negative → stop.
        - If current number > 9 → stop.
        - If count == k before reaching sum 0 → stop.

    Each number can be used only once, so after picking:
        idx + 1

    Time Complexity: O(2^9)
    Space Complexity: O(k)

    Key Learning:
    Combination Sum III uses numbers 1 to 9,
    each number can be used at most once,
    and exactly k numbers must be selected.

    Revision Note:
    Pick → idx + 1, sum - idx, count + 1
    Not Pick → idx + 1, sum unchanged
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void sum(int idx, int n, int k, int count,
             vector<int>& arr, vector<vector<int>>& ans) {

        // Valid combination found
        if (n == 0 && count == k) {
            ans.push_back(arr);
            return;
        }

        // Pruning
        if (n < 0 || idx > 9 || count == k)
            return;

        // Pick
        arr.push_back(idx);

        sum(idx + 1,
            n - idx,
            k,
            count + 1,
            arr,
            ans);

        // Backtrack
        arr.pop_back();

        // Not Pick
        sum(idx + 1,
            n,
            k,
            count,
            arr,
            ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> arr;

        sum(1, n, k, 0, arr, ans);

        return ans;
    }
};

int main() {
    return 0;
}