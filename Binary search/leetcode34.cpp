/*
    Problem: Find First and Last Position of Element in Sorted Array
    Topic: Binary Search
    Pattern: Lower Bound + Upper Bound
    Approach:
    Use binary search twice.
    1. First Binary Search:
       Find the first index where nums[i] >= target.
       If nums[st] == target, this is the first occurrence.
    2. Second Binary Search:
       Find the last index where nums[i] <= target.
       This gives the last occurrence of target.
    Time Complexity: O(log n)
    Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int st = -1;
        int end = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                st = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (st == -1 || nums[st] != target) {
            return {-1, -1};
        }
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                end = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {st, end};
    }
};
int main() {
    return 0;
}