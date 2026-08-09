/*
    Problem: Search in Rotated Sorted Array II
    Pattern: Modified Binary Search + Duplicates
    Approach:
    Use modified binary search.
    At every step, identify which half is sorted.
    Special Case:
    If nums[left] == nums[mid] && nums[mid] == nums[right],
    we cannot determine which half is sorted.
    So:
    left++;
    right--;
    Otherwise, check the sorted half and determine
    whether the target lies inside its range.
    Time Complexity:
    Average: O(log n
    Worst Case: O(n) due to duplicates
    Space Complexity: O(1)
    Key Learning:
    When left, mid and right have the same value,
    shrink the search space from both sides.
    nums[left] == nums[mid] == nums[right]
    left++ and right--
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}