/*
    Problem: Search in a 2D Matrix II

    Topic: Matrix / Binary Search

    Pattern: Staircase Search

    Brute Force:
    Traverse every element and check if it is equal to the target.

    Time Complexity: O(n * m)
    Space Complexity: O(1)

    Optimal Approach:
    Start from the top-right corner.

    At matrix[row][column]:

    1. If element == target:
       Return true.

    2. If element > target:
       Move left because all elements below are greater.

    3. If element < target:
       Move down because all elements to the left are smaller.

    Continue until we either find the target or go outside
    the matrix.

    Time Complexity: O(n + m)
    Space Complexity: O(1)

    Key Learning:
    In a row-wise and column-wise sorted matrix,
    start from the top-right corner.

    Bigger than target → move LEFT
    Smaller than target → move DOWN

    Revision Note:
    Top-right → bigger: left, smaller: down.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = 0;
        int column = matrix[0].size() - 1;

        while (row <= matrix.size() - 1 && column >= 0) {

            if (matrix[row][column] == target)
                return true;

            else if (matrix[row][column] > target)
                column--;

            else
                row++;
        }

        return false;
    }
};

int main() {
    return 0;
}