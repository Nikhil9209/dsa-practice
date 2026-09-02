/*
    Problem: Row With Maximum 1s

    Topic: Binary Search / 2D Array

    Pattern: Lower Bound

    Brute Force:
    Count the number of 1s in every row by traversing each element.
    Time Complexity: O(n * m)

    Optimal Approach:
    Since every row is sorted, find the first occurrence of 1
    using lower bound.

    Number of 1s in a row:
    total columns - index of first 1

    Keep track of the row having the maximum number of 1s.

    Time Complexity: O(n * log(m))
    Space Complexity: O(1)

    Key Learning:
    In a sorted binary row, lower_bound(1) gives the first 1.
    Number of 1s = columns - firstOneIndex.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lowerBound(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= k) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int count = 0;
        int index = -1;

        for (int i = 0; i < arr.size(); i++) {
            int countocc = arr[i].size() - lowerBound(arr[i], 1);

            if (countocc > count) {
                count = countocc;
                index = i;
            }
        }

        return index;
    }
};

int main() {
    return 0;
}