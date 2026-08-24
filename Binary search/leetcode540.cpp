/*
    Problem: Single Element in a Sorted Array

    Topic: Binary Search

    Pattern: Modified Binary Search


    Optimal Approach:
    Use binary search.

    Before the single element, pairs follow:
    even index -> odd index

    After the single element, this pattern breaks.

    If mid is odd and nums[mid-1] == nums[mid],
    the single element lies on the right.

    If mid is even and nums[mid] == nums[mid+1],
    the single element lies on the right.

    Otherwise, the single element lies on the left.

    Edge Cases:
    Check the first and last elements separately.

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Key Learning:
    Before single element:
    (even, odd) -> valid pair

    After single element:
    (odd, even) -> valid pair

    Pattern:
    Even index + next element should be the pair
    before the single element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Found the single element
            if (nums[mid] != nums[mid + 1] &&
                nums[mid - 1] != nums[mid]) {
                return nums[mid];
            }

            // Single element is on the right
            if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
                (mid % 2 == 0 && nums[mid + 1] == nums[mid])) {
                low = mid + 1;
            }

            // Single element is on the left
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