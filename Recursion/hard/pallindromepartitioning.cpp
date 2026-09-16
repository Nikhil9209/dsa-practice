/*
    Problem: Palindrome Partitioning

    Topic: Recursion / Backtracking / Strings

    Pattern: Backtracking + Partitioning

    Brute Force:
    Generate all possible ways to partition the string and check
    whether every substring in the partition is a palindrome.

    Time Complexity: O(2^n * n) approximately
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Optimal Approach:
    Start from index 0 and try every possible substring starting
    from the current index.

    For every possible ending index `i`:

        1. Check whether s[idx...i] is a palindrome.
        2. If it is a palindrome:
           - Add the substring to the current partition.
           - Recursively partition the remaining string from i + 1.
           - Backtrack by removing the substring.

    Base Case:
        If idx == s.length():
        The complete string has been partitioned into palindromes,
        so add the current partition to the answer.

    Example:
        s = "aab"

        Possible partitions:
        ["a", "a", "b"]
        ["aa", "b"]

    Time Complexity: O(2^n * n)
    Space Complexity: O(n)

    Key Learning:
    At every index, try every possible substring starting from
    that index, but continue recursion only if that substring
    is a palindrome.

    Revision Note:
    Choose substring → Check palindrome → Recurse → Backtrack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Check whether s[left...right] is a palindrome
    bool pallindrome(int left, int right, string s) {

        while (left <= right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void checkStr(int idx,
                  string s,
                  vector<string>& temp,
                  vector<vector<string>>& ans) {

        // Complete partition formed
        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring
        for (int i = idx; i < s.length(); i++) {

            // Only choose palindrome substring
            if (pallindrome(idx, i, s)) {

                temp.push_back(
                    s.substr(idx, i - idx + 1)
                );

                // Process remaining string
                checkStr(i + 1, s, temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> temp;
        vector<vector<string>> ans;

        checkStr(0, s, temp, ans);

        return ans;
    }
};

int main() {
    return 0;
}