/*
    Problem: 01 Matrix

    Topic: Graph / BFS

    Pattern: Multi-Source BFS

    Brute Force:
    For every cell containing 1, find the nearest 0 using BFS/DFS.
    This repeats the same work many times.

    Optimal Approach:
    Start BFS from all 0s simultaneously.
    Put every 0 into the queue with distance 0.
    Then visit the neighboring cells level by level.
    The first time we reach a cell, we have found its minimum
    distance from any 0.

    Time Complexity: O(m * n)
    Space Complexity: O(m * n)

    Key Learning:
    When we need the shortest distance from multiple starting
    points, use Multi-Source BFS.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Put all 0s into the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   ans[nr][nc] == -1) {

                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}