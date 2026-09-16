/*
    Problem: Letter Combinations of a Phone Number

    Topic: Recursion / Backtracking / String

    Pattern: Pick One Character for Each Digit

    Brute Force:
    Generate all possible combinations of letters for the given
    digits and store them.

    Each digit has either 3 or 4 possible letters.

    Time Complexity: O(4^n * n)
    Space Complexity: O(n) recursion stack
                      (excluding the output)

    Optimal Approach:
    Use recursion to process one digit at a time.

    For the current digit:
        1. Convert the digit character into an integer.
        2. Get all letters mapped to that digit.
        3. Try each letter.
        4. Add it to the current combination.
        5. Recursively process the next digit.

    Base Case:
        If idx == digits.length(),
        one complete combination is formed.

    Example:
        digits = "23"

        2 → abc
        3 → def

        Combinations:
        ad, ae, af
        bd, be, bf
        cd, ce, cf

    Time Complexity: O(4^n * n)
    Space Complexity: O(n) recursion stack
                      (excluding output)

    Key Learning:
    At each digit, try every possible letter mapped to that digit.

    Revision Note:
    Digit → letters
    Pick one letter → move to next digit
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void ansStr(int idx,
                string digits,
                vector<string>& ans,
                string combo,
                vector<string>& combination) {

        // Complete combination formed
        if (idx == digits.length()) {
            ans.push_back(combo);
            return;
        }

        // Convert character digit to integer
        int number = digits[idx] - '0';

        // Try every letter for current digit
        for (int i = 0; i < combination[number].size(); i++) {

            ansStr(
                idx + 1,
                digits,
                ans,
                combo + combination[number][i],
                combination
            );
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> combination = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;

        if (digits.empty())
            return ans;

        ansStr(0, digits, ans, "", combination);

        return ans;
    }
};

int main() {
    return 0;
}