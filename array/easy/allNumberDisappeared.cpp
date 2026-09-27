/*
    Problem: Find All Numbers Disappeared in an Array

    Topic: Arrays / Hashing

    Pattern: Frequency Array / Hashing

    Brute Force:
    For every number from 1 to n, search whether it exists
    in the array.
    This takes O(n^2).

    Optimal Approach:
    Use a frequency array of size n + 1.
    For every number in nums, increase its frequency.
    Then traverse from 1 to n.
    If frequency[i] == 0, number i is missing.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Key Learning:
    When values are in the range 1 to n, a frequency array
    can be used to quickly find missing numbers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> hash_map(nums.size() + 1, 0);
        vector<int> ans;

        // Store frequency of each number
        for(int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]]++;
        }

        // Find numbers whose frequency is 0
        for(int i = 1; i <= nums.size(); i++) {

            if(hash_map[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    return 0;
}