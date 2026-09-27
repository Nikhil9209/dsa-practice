/*
    Problem: Remove Element

    Topic: Arrays

    Pattern: Two Pointers / In-Place Modification

    Brute Force:
    Whenever nums[i] == val, remove that element and shift
    all elements after it to the left.
    This can take O(n^2).

    Optimal Approach:
    Use two pointers:
    - i → scans every element
    - j → stores the next position for an element that is
          not equal to val

    If nums[i] != val, copy it to nums[j] and increment j.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    To remove elements in-place, overwrite unwanted elements
    using a write pointer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int removeElement(vector<int>& nums, int val) {

        int j = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};

int main() {
    return 0;
}