/*
    Problem: Minimum Number of Days to Make m Bouquets

    Topic: Binary Search

    Pattern: Binary Search on Answer

    Optimal Approach:
    Apply Binary Search on the answer (number of days).

    For a particular day:
    - bloomDay[i] <= day -> flower is bloomed
    - Count consecutive bloomed flowers
    - Every k consecutive flowers form one bouquet

    If bouquets >= m:
    -> Current day is possible
    -> Try fewer days

    If bouquets < m:
    -> Need more days
    -> Move to the right

    Time Complexity: O(n * log(maxDay))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Answer

    m = required number of bouquets
    k = flowers required for each bouquet

    Possible -> high = mid - 1
    Not Possible -> low = mid + 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int mini(vector<int>& bloomDay, int n) {
        int mini = INT_MAX;

        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
        }

        return mini;
    }

    int maxi(vector<int>& bloomDay, int n) {
        int maxi = INT_MIN;

        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
        }

        return maxi;
    }

    int isOk(vector<int>& bloomDay, int day, int n, int k) {

        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++) {

            if (bloomDay[i] <= day) {
                count++;

                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            }
            else {
                count = 0;
            }
        }

        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = mini(bloomDay, bloomDay.size());
        int high = maxi(bloomDay, bloomDay.size());
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int bouquets = isOk(
                bloomDay,
                mid,
                bloomDay.size(),
                k
            );

            if (bouquets >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}