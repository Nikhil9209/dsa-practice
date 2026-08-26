/*
    Problem: Capacity to Ship Packages Within D Days

    Topic: Binary Search

    Pattern: Binary Search on Answer


    Optimal Approach:
    Use Binary Search on the ship capacity.

    Search Range:
    low = maximum weight
    high = sum of all weights

    Why low = maximum weight?
    A package cannot be split, so the ship capacity must be
    at least as large as the heaviest package.

    Why high = total weight?
    In the worst case, all packages can be shipped in one day.

    For a particular capacity:
    Calculate the number of days required.

    If requiredDays <= days:
    -> Current capacity is possible.
    -> Try a smaller capacity.
    -> Move left.

    If requiredDays > days:
    -> Capacity is too small.
    -> Increase the capacity.
    -> Move right.

    Time Complexity: O(n * log(sum(weights)))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Answer

    Capacity works:
    requiredDays <= days
    -> high = mid - 1

    Capacity does not work:
    requiredDays > days
    -> low = mid + 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sum(vector<int>& weights, int n) {

        long long total = 0;

        for (int i = 0; i < n; i++) {
            total += weights[i];
        }

        return total;
    }

    int validDay(vector<int>& weights, int capacity, int n) {

        int day = 1;
        int currentSum = 0;

        for (int i = 0; i < n; i++) {

            if (currentSum + weights[i] > capacity) {
                day++;
                currentSum = weights[i];
            }
            else {
                currentSum += weights[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = sum(weights, n);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int requiredDays = validDay(weights, mid, n);

            if (requiredDays <= days) {
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