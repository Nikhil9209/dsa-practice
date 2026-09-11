/*
    Problem: Generate Parentheses

    Topic: Recursion / Backtracking

    Pattern: Backtracking with Constraints

    Brute Force:
    Generate all possible strings of length 2*n using '(' and ')'
    and check which strings are valid parentheses sequences.

    Time Complexity: O(2^(2n)) approximately, followed by validation.
    Space Complexity: O(n) for recursion.

    Optimal Approach:
    Build the parentheses string while maintaining two counts:
    
        open  = number of '(' used
        close = number of ')' used

    Rules:

    1. We can add '(' while:
           open < n

    2. We can add ')' only when:
           close < open

       This ensures that we never have more closing parentheses
       than opening parentheses at any point.

    3. When:
           open == n && close == n

       We have generated one valid answer.

    Time Complexity: O(Cn * n)
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Key Learning:
    In backtracking, don't generate invalid choices.

    '(' → allowed if open < n
    ')' → allowed if close < open

    Revision Note:
    Generate '(' freely until n.
    Generate ')' only when close < open.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void paranthesis(int open, int close, int n,
                     string s, vector<string>& ans) {

        if (open == close && open + close == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket
        if (open < n) {
            paranthesis(open + 1, close, n, s + '(', ans);
        }

        // Add closing bracket
        if (close < open) {
            paranthesis(open, close + 1, n, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        paranthesis(0, 0, n, "", ans);

        return ans;
    }
};

int main() {
    return 0;
}