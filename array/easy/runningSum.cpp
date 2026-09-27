/*
    Problem: Running Sum of 1d Array

    Topic: Arrays

    Pattern: Prefix Sum / Running Sum

    Brute Force:
    For every index, calculate the sum of all elements from
    index 0 to the current index.
    This takes O(n^2).

    Optimal Approach:
    Maintain a variable `sum` to store the cumulative sum.
    At every index, add nums[i] to sum and store the result
    back into nums[i].

    This modifies the array in-place.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    When the answer depends on the sum of previous elements,
    maintain a running/prefix sum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {

        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
    }
};

int main() {
    return 0;
}