/*
    Problem: Two Sum

    Topic: Array + Hashing

    Pattern: Hash Map / Complement Lookup

    Brute Force:
    Check every pair of elements using two nested loops
    and return the indices whose sum equals target.

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    Optimal Approach:
    Use an unordered_map to store each number and its index.

    For every nums[i]:
    1. Calculate the required complement:
       rem = target - nums[i]

    2. Check if rem already exists in the map.
       If yes, the required pair is found.

    3. Otherwise, store nums[i] and its index.

    Time Complexity: O(n) average
    Space Complexity: O(n)

    Key Learning:
    Two Sum -> Hashing

    Required value = target - current value

    Store previous elements so that the complement
    can be found in O(1) average time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {

            int rem = target - nums[i];

            if (mpp.find(rem) != mpp.end()) {
                return {mpp[rem], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main() {
    return 0;
}