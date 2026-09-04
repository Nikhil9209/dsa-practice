/*
    Problem: Find a Peak Element II

    Topic: Binary Search / 2D Matrix

    Pattern: Binary Search on Columns + Find Maximum in Column

    Brute Force:
    Check every cell and compare it with its four neighbors.
    If a cell is greater than all its valid neighbors, it is a peak.

    Time Complexity: O(m * n)
    Space Complexity: O(1)

    Optimal Approach:
    Apply binary search on the columns.

    For the middle column:
    1. Find the row having the maximum element in that column.
    2. Since it is the maximum in its column, it is already greater
       than its top and bottom neighbors.
    3. Only compare it with its left and right neighbors.

    If current element is greater than both left and right:
        It is a peak → return its position.

    If left neighbor is greater:
        A peak must exist on the left side.
        high = mid - 1

    Otherwise:
        A peak must exist on the right side.
        low = mid + 1

    Time Complexity: O(m * log(n))
    Space Complexity: O(1)

    Key Learning:
    Binary search can be applied to one dimension while scanning
    the other dimension to find the maximum element.

    Revision Note:
    Binary search on columns → find column maximum → compare LEFT/RIGHT.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Find maximum element in current column
            int maxRow = 0;

            for (int row = 1; row < m; row++) {
                if (mat[row][mid] > mat[maxRow][mid]) {
                    maxRow = row;
                }
            }

            int left = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;

            // Current element is a peak
            if (mat[maxRow][mid] > left &&
                mat[maxRow][mid] > right) {

                return {maxRow, mid};
            }

            // Peak lies on the left
            if (left > mat[maxRow][mid]) {
                high = mid - 1;
            }

            // Peak lies on the right
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    return 0;
}