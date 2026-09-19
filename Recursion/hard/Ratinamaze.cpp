/*
    Problem: Rat in a Maze

    Topic: Recursion / Backtracking / Matrix

    Pattern: Backtracking with Visited Marking

    Brute Force:
    Try all four possible directions from every cell:
        Up, Left, Right, Down

    Keep exploring until:
        - Destination is reached
        - A blocked/visited cell is encountered
        - We move outside the matrix

    Time Complexity: O(4^(n^2)) in the worst case
    Space Complexity: O(n^2) for recursion/visited state
                      (excluding the output)

    Optimal Approach:
    Start from the top-left cell and recursively explore all
    possible paths to the bottom-right cell.

    At every cell:
        1. Mark the current cell as visited.
        2. Try all four valid directions.
        3. Add the direction to `path`.
        4. Recursively move to the next cell.
        5. Remove the direction while backtracking.
        6. Unmark the current cell.

    Directions:
        U → Up
        L → Left
        R → Right
        D → Down

    Base Case:
        If current cell is the destination:
            Store the current path.

    Key Learning:
    In grid backtracking, mark a cell as visited before
    exploring it and unmark it after all possible paths
    from that cell have been explored.

    Revision Note:
    Mark → Explore → Backtrack → Unmark
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void func(int i, int j,
              vector<vector<int>>& grid,
              string& path,
              vector<string>& ans) {

        // Destination reached
        if (i == grid.size() - 1 &&
            j == grid.size() - 1) {

            ans.push_back(path);
            return;
        }

        // Mark current cell as visited
        grid[i][j] = 0;

        // Up
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {

            path.push_back('U');

            func(i - 1, j, grid, path, ans);

            path.pop_back();
        }

        // Left
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {

            path.push_back('L');

            func(i, j - 1, grid, path, ans);

            path.pop_back();
        }

        // Right
        if (j + 1 < grid.size() && grid[i][j + 1] == 1) {

            path.push_back('R');

            func(i, j + 1, grid, path, ans);

            path.pop_back();
        }

        // Down
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {

            path.push_back('D');

            func(i + 1, j, grid, path, ans);

            path.pop_back();
        }

        // Backtrack: unmark current cell
        grid[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<string> ans;
        string path = "";

        if (grid[0][0] != 1 ||
            grid[n - 1][n - 1] != 1) {

            return ans;
        }

        func(0, 0, grid, path, ans);

        return ans;
    }
};

int main() {
    return 0;
}