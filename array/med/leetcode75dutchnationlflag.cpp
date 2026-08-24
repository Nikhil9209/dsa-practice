/*
    Problem: Sort Colors

    Topic: Array

    Pattern: Dutch National Flag Algorithm / Three Pointers

    Optimal Approach:
    Use three pointers:

    left  -> position where 0 should be placed
    mid   -> current element
    right -> position where 2 should be placed

    If nums[mid] == 0:
    -> Swap with left
    -> Move left and mid

    If nums[mid] == 1:
    -> Already in correct region
    -> Move mid

    If nums[mid] == 2:
    -> Swap with right
    -> Move right only
    -> Do NOT move mid because the swapped element
       from the right has not been processed yet.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    0 -> left side
    1 -> middle
    2 -> right side

    Pattern:
    [0 ... left-1]     -> 0
    [left ... mid-1]   -> 1
    [mid ... right]    -> unknown
    [right+1 ... n-1]  -> 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;

        while (mid <= right) {

            if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }

            else if (nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[right], nums[mid]);
                right--;
            }
        }
    }
};

int main() {
    return 0;
}