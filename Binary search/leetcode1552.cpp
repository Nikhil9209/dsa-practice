/*
    Problem: Magnetic Force Between Two Balls

    Topic: Binary Search

    Pattern: Binary Search on Answer + Greedy
    Optimal Approach:
    Sort the positions first.

    Apply Binary Search on the minimum possible distance.

    Search Range:
    low = 1
    high = position[n - 1] - position[0]

    For a particular distance:
    Place the first ball at the first position.
    Then greedily place every next ball at the earliest
    position whose distance from the previous ball is
    at least mid.

    If we can place at least m balls:
    -> Current distance is possible.
    -> Try a larger distance.
    -> Move right.

    If we cannot place m balls:
    -> Current distance is not possible.
    -> Try a smaller distance.
    -> Move left.

    Time Complexity: O(n log n + n log(maxDistance))
    Space Complexity: O(1) excluding sorting.

    Key Learning:
    Binary Search on Answer + Greedy

    Valid distance:
    count >= m
    -> low = mid + 1

    Invalid distance:
    count < m
    -> high = mid - 1

    Greedy Idea:
    Always place the next ball at the earliest possible
    position to maximize the chance of placing more balls.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(vector<int>& position, int mid, int n, int m) {

        int end = position[0];
        int count = 1;

        for (int i = 1; i < n; i++) {

            if (position[i] - end >= mid) {
                count++;
                end = position[i];
            }
        }

        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int n = position.size();

        int low = 1;
        int high = position[n - 1] - position[0];

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isValid(position, mid, n, m)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}