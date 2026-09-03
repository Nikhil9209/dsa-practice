/*
    Problem: Search a 2D Matrix

    Topic: Binary Search / 2D Matrix

    Pattern: Binary Search on Flattened Matrix

    Optimal Approach:
    Treat the 2D matrix as a sorted 1D array and apply binary search.

    For a flattened index `mid`:
    
        row = mid / m
        col = mid % m

    So the actual element is:
    
        matrix[mid / m][mid % m]

    If element == target → return true
    If element > target → search left
    If element < target → search right

    Time Complexity: O(log(n * m))
    Space Complexity: O(1)

    Key Learning:
    A row-wise sorted matrix with the first element of each row
    greater than the last element of the previous row can be treated
    like one sorted 1D array.

    Revision Note:
    mid / columns → row
    mid % columns → column
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = (m * n) - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int ele = matrix[mid / m][mid % m];

            if (ele == target)
                return true;

            else if (ele > target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return false;
    }
};

int main() {
    return 0;
}