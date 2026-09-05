/*
    Problem: Remove Outermost Parentheses

    Topic: String / Stack Concept

    Pattern: Track Parentheses Depth

    Brute Force:
    Split the string into primitive valid parentheses strings and
    remove the first '(' and last ')' from each primitive string.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Optimal Approach:
    Maintain a `depth` variable to track the current nesting level.

    For '(':
        - If depth > 0, it is not an outermost '(' → add it.
        - Increase depth.

    For ')':
        - Decrease depth first.
        - If depth > 0, it is not an outermost ')' → add it.

    Example:
        s = "(()())"

        Outer '(' and ')' are removed:

        "(()())" → "()()"

    Time Complexity: O(n)
    Space Complexity: O(n)

    Key Learning:
    Use depth to identify outermost parentheses.

    '(' → add only if depth > 0, then depth++
    ')' → depth-- first, add only if depth > 0

    Revision Note:
    Opening bracket: check before increment.
    Closing bracket: decrement first, then check.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string removeOuterParentheses(string s) {

        string ans;
        int depth = 0;

        for (char ch : s) {

            if (ch == '(') {

                if (depth > 0) {
                    ans += ch;
                }

                depth++;
            }
            else {

                depth--;

                if (depth > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}