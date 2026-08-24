
/*
    Problem: Find Peak Element

    Topic: Binary Search

    Pattern: Modified Binary Search

    Optimal Approach:
    Use binary search.

    If nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1],
    then mid is a peak.

    If nums[mid] > nums[mid - 1],
    we are on an increasing slope,
    so a peak exists on the right side.

    Otherwise, we are on a decreasing slope,
    so a peak exists on the left side.

    Edge Cases:
    If the first element is greater than the second,
    index 0 is a peak.

    If the last element is greater than the second-last,
    index n-1 is a peak.

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Key Learning:
    Increasing slope -> move right
    Decreasing slope -> move left

    We don't need to find the maximum element.
    We only need to find any peak.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        int low = 1;
        int high = n - 2;

        if (n == 1)
            return 0;

        if (nums[0] > nums[1])
            return 0;

        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {
                return mid;
            }

            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}
