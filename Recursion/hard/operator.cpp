class Solution {
public:

    void solve(int idx, string s, long long target,
               string exp, long long value, long long prev,
               vector<string>& ans) {

        // If we have used all digits
        if (idx == s.size()) {
            if (value == target) {
                ans.push_back(exp);
            }
            return;
        }

        long long num = 0;

        for (int i = idx; i < s.size(); i++) {

            // Don't allow numbers like 05, 00
            if (i > idx && s[idx] == '0')
                break;

            num = num * 10 + (s[i] - '0');

            string part = s.substr(idx, i - idx + 1);

            // First number
            if (idx == 0) {
                solve(i + 1, s, target,
                      part, num, num, ans);
            }
            else {

                // +
                solve(i + 1, s, target,
                      exp + "+" + part,
                      value + num,
                      num,
                      ans);

                // -
                solve(i + 1, s, target,
                      exp + "-" + part,
                      value - num,
                      -num,
                      ans);

                // *
                solve(i + 1, s, target,
                      exp + "*" + part,
                      value - prev + prev * num,
                      prev * num,
                      ans);
            }
        }
    }

    vector<string> addOperators(string s, int target) {

        vector<string> ans;

        solve(0, s, target, "", 0, 0, ans);

        return ans;
    }
};class Solution {
public:

    void solve(int idx, string s, long long target,
               string exp, long long value, long long prev,
               vector<string>& ans) {

        // If we have used all digits
        if (idx == s.size()) {
            if (value == target) {
                ans.push_back(exp);
            }
            return;
        }

        long long num = 0;

        for (int i = idx; i < s.size(); i++) {

            // Don't allow numbers like 05, 00
            if (i > idx && s[idx] == '0')
                break;

            num = num * 10 + (s[i] - '0');

            string part = s.substr(idx, i - idx + 1);

            // First number
            if (idx == 0) {
                solve(i + 1, s, target,
                      part, num, num, ans);
            }
            else {

                // +
                solve(i + 1, s, target,
                      exp + "+" + part,
                      value + num,
                      num,
                      ans);

                // -
                solve(i + 1, s, target,
                      exp + "-" + part,
                      value - num,
                      -num,
                      ans);

                // *
                solve(i + 1, s, target,
                      exp + "*" + part,
                      value - prev + prev * num,
                      prev * num,
                      ans);
            }
        }
    }

    vector<string> addOperators(string s, int target) {

        vector<string> ans;

        solve(0, s, target, "", 0, 0, ans);

        return ans;
    }
};