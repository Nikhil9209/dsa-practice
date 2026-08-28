/*
    Problem: Aggressive Cows

    Topic: Binary Search

    Pattern: Binary Search on Answer

    Optimal Approach:
    Sort the stalls first.

    Apply Binary Search on the minimum possible distance.

    Search Range:
    low = 1
    high = arr[n - 1] - arr[0]

    For a particular distance:
    Greedily place the first cow at the first stall.
    Then place every next cow at the earliest stall whose
    distance from the previous cow is at least mid.

    If we can place at least k cows:
    -> Current distance is possible.
    -> Try a larger distance.
    -> Move right.

    If we cannot place k cows:
    -> Current distance is not possible.
    -> Try a smaller distance.
    -> Move left.

    Time Complexity: O(n log n + n log(maxDistance))
    Space Complexity: O(1) excluding sorting.

    Key Learning:
    Binary Search on Answer

    Possible distance:
    count >= k
    -> low = mid + 1

    Not possible:
    count < k
    -> high = mid - 1

    Greedy idea:
    Always place the next cow at the earliest possible stall.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(vector<int>& arr, int mid, int n, int k) {

        int end = arr[0];
        int count = 1;

        for (int i = 1; i < n; i++) {

            if (arr[i] - end >= mid) {
                count++;
                end = arr[i];
            }
        }

        return count >= k;
    }

    int aggressiveCows(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int low = 1;
        int high = arr[n - 1] - arr[0];

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isValid(arr, mid, n, k)) {
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