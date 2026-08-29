/*
    Problem: Allocate Books / Split Array Largest Sum

    Topic: Binary Search

    Pattern: Binary Search on Answer + Greedy


    Optimal Approach:
    Use Binary Search on Answer.

    Search Range:
    low = maximum element
    high = sum of all elements

    For a particular mid:
    Check whether it is possible to divide the array into
    at most k parts with each part having sum <= mid.

    If mid is valid:
    -> Current maximum sum is possible.
    -> Try a smaller answer.
    -> high = mid - 1

    If mid is not valid:
    -> We need a larger maximum sum.
    -> low = mid + 1

    Time Complexity: O(n * log(sum(nums)))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Answer

    low = maximum element
    high = total sum

    Valid -> high = mid - 1
    Invalid -> low = mid + 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(vector<int>& nums, int mid, int k) {

        // Check whether nums can be divided
        // into at most k parts with sum <= mid.

        int count = 1;
        long long currentSum = 0;

        for (int x : nums) {

            if (currentSum + x <= mid) {
                currentSum += x;
            }
            else {
                count++;
                currentSum = x;
            }
        }

        return count <= k;
    }

    int solve(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());

        long long high = 0;

        for (int x : nums) {
            high += x;
        }

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isValid(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}