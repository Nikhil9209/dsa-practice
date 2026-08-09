/*
    Problem: Count Frequency of an Element in a Sorted Array
    Topic: Binary Search
    Pattern: First Occurrence + Last Occurrence
    Approach:
    Use binary search twice.
    Frequency = Last Occurrence - First Occurrence + 1
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int st = -1;
        int end = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                st = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (st == -1 || arr[st] != target) {
            return 0;
        }
        left = 0;
        right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                end = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return end - st + 1;
    }
};
int main() {
    return 0;
}