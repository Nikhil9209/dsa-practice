/*
    Pattern: Binary Search
    Approach :Upper Bound = first index where arr[i] > target.
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int ans = arr.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > target) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};