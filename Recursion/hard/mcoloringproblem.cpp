/*
    Problem: M-Coloring Problem

    Topic: Graph / Backtracking

    Pattern: Graph Coloring + Backtracking

    Brute Force:
    Try every possible color combination for all vertices.
    There are m^n possible color assignments in the worst case.

    Optimal Approach:
    Use backtracking.
    For each node, try colors from 1 to m.
    Before assigning a color, check whether any adjacent node
    already has the same color.
    
    If the color is valid, assign it and move to the next node.
    If the next nodes cannot be colored, undo the color
    and try another color.

    Time Complexity: O(m^n) in the worst case
    Space Complexity: O(n + E)

    Key Learning:
    Graph + "try all choices" + undo when invalid = Backtracking.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool possible(int node, int num, vector<int> adj[], vector<int>& color) {

        for(int i = 0; i < adj[node].size(); i++) {

            int adjnode = adj[node][i];

            if(color[adjnode] == num)
                return false;
        }

        return true;
    }

    bool solve(int node, int m, int n, vector<int> adj[], vector<int>& color) {

        // All nodes are colored
        if(node == n)
            return true;

        // Try every color
        for(int num = 1; num <= m; num++) {

            if(possible(node, num, adj, color)) {

                color[node] = num;

                if(solve(node + 1, m, n, adj, color))
                    return true;

                // Backtrack
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>>& edges, int m, int n) {

        vector<int> adj[n];

        // Create adjacency list
        for(int i = 0; i < edges.size(); i++) {

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> color(n, 0);

        return solve(0, m, n, adj, color);
    }
};

int main() {
    return 0;
}/*
    Problem: M-Coloring Problem

    Topic: Graph / Backtracking

    Pattern: Graph Coloring + Backtracking

    Brute Force:
    Try every possible color combination for all vertices.
    There are m^n possible color assignments in the worst case.

    Optimal Approach:
    Use backtracking.
    For each node, try colors from 1 to m.
    Before assigning a color, check whether any adjacent node
    already has the same color.
    
    If the color is valid, assign it and move to the next node.
    If the next nodes cannot be colored, undo the color
    and try another color.

    Time Complexity: O(m^n) in the worst case
    Space Complexity: O(n + E)

    Key Learning:
    Graph + "try all choices" + undo when invalid = Backtracking.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool possible(int node, int num, vector<int> adj[], vector<int>& color) {

        for(int i = 0; i < adj[node].size(); i++) {

            int adjnode = adj[node][i];

            if(color[adjnode] == num)
                return false;
        }

        return true;
    }

    bool solve(int node, int m, int n, vector<int> adj[], vector<int>& color) {

        // All nodes are colored
        if(node == n)
            return true;

        // Try every color
        for(int num = 1; num <= m; num++) {

            if(possible(node, num, adj, color)) {

                color[node] = num;

                if(solve(node + 1, m, n, adj, color))
                    return true;

                // Backtrack
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>>& edges, int m, int n) {

        vector<int> adj[n];

        // Create adjacency list
        for(int i = 0; i < edges.size(); i++) {

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> color(n, 0);

        return solve(0, m, n, adj, color);
    }
};

int main() {
    return 0;
}