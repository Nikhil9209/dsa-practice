/*
    Problem: Find K Rotation
    Pattern: Modified Binary Search
    Approach:
    Use modified binary search to find the minimum element
    and store its index.
    If the current range is already sorted:
    arr[low] <= arr[high]
    -> arr[low] is the minimum.
    If the left half is sorted:
    arr[low] <= arr[mid]
    -> minimum can be arr[low]
    -> search in the right half.
    Otherwise:
    -> minimum can be arr[mid]
    -> search in the left half.
    Number of rotations = index of minimum element.
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKRotation(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = INT_MAX;
        int idx = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[high]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    idx = low;
                }
                break;
            }
            else if (arr[low] <= arr[mid]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    idx = low;
                }
                low = mid + 1;
            }
            else {
                if (arr[mid] < ans) {
                    ans = arr[mid];
                    idx = mid;
                }
                high = mid - 1;
            }
        }
        return idx;
    }
};
int main() {
    return 0;
}