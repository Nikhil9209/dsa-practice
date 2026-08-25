/*
    Problem: Majority Element

    Topic: Array

    Pattern: Moore's Voting Algorithm
    Optimal Approach:
    Use Moore's Voting Algorithm.

    Maintain:
    ele -> current majority candidate
    cnt -> candidate's vote count

    If nums[i] == ele:
    -> Increase count.

    If cnt == 0:
    -> Choose nums[i] as the new candidate.

    Otherwise:
    -> Decrease count because the current element
       cancels one vote of the candidate.

    Since the majority element appears more than n/2 times,
    it will remain as the final candidate.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    Different elements cancel each other out.
    The element appearing more than n/2 times survives.

    Pattern:
    Same element -> cnt++
    Different element -> cnt--
    cnt == 0 -> new candidate
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int cnt = 0;
        int ele = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            if (ele == nums[i]) {
                cnt++;
            }

            else if (cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }

            else {
                cnt--;
            }
        }

        return ele;
    }
};

int main() {
    return 0;
}