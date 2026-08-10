/*
    Problem: Find Minimum in Rotated Sorted Array

    Pattern: Modified Binary Search
    Approach:
    Use modified binary search.
    If nums[left] <= nums[right], the current range is already
    sorted, so nums[left] is the minimum of this range.
    If the left half is sorted:
    nums[left] <= nums[mid]
    -> nums[left] can be the minimum
    -> search in the right half
    Otherwise:
    -> the minimum lies in the left side including mid
    -> search in the left half
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[right]) {
                ans = min(ans, nums[left]);
            }
            if (nums[left] <= nums[mid]) {
                ans = min(ans, nums[left]);
                left = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}