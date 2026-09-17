/*
    Problem: N-Queens

    Topic: Recursion / Backtracking

    Pattern: Backtracking + Board Validation

    Brute Force:
    Try placing queens in every possible position on the board
    and check whether the final arrangement is valid.

    Time Complexity: O(N! * N)
    Space Complexity: O(N^2) for the board
                      + O(N) recursion stack
                      (excluding the output)

    Optimal Approach:
    Place exactly one queen in each row.

    For every row:
        1. Try every column.
        2. Check whether placing a queen is safe.
        3. If safe, place the queen.
        4. Recursively move to the next row.
        5. Remove the queen while backtracking.

    To check whether a position is safe, check:
        - Same column
        - Same row
        - Upper-left diagonal
        - Upper-right diagonal

    Since we place only one queen in each row,
    checking the current row is not actually necessary,
    but it does not affect the correctness.

    Base Case:
        row == n
        → All queens have been placed successfully.
        → Store the board.

    Time Complexity: O(N! * N)
    Space Complexity: O(N^2)

    Key Learning:
    In N-Queens, place one queen row by row and backtrack
    whenever the current position is unsafe.

    Revision Note:
    Row → try every column → check safe → place Q → recurse
    → remove Q.

    Important:
    One queen per row automatically prevents
    multiple queens from being placed in the same row.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(int row, int col, vector<string>& temp, int n) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (temp[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (temp[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (temp[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void func(int row,
              vector<string>& temp,
              vector<vector<string>>& ans,
              int n) {

        // All queens placed
        if (row == n) {
            ans.push_back(temp);
            return;
        }

        // Try every column in current row
        for (int col = 0; col < n; col++) {

            if (check(row, col, temp, n)) {

                // Place queen
                temp[row][col] = 'Q';

                func(row + 1, temp, ans, n);

                // Backtrack
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> temp(n, string(n, '.'));

        func(0, temp, ans, n);

        return ans;
    }
};

int main() {
    return 0;
}