/*
    Problem: Minimum Time to Complete Jobs

    Topic: Binary Search

    Pattern: Binary Search on Answer + Greedy

    Optimal Approach:
    Use Binary Search on Answer.

    Search Range:
    low = maximum time required for a single job
    high = total time required for all jobs

    For a particular mid:
    Greedily assign consecutive jobs to the current worker
    until adding the next job exceeds mid.

    If required workers <= k:
    -> Current maximum time is possible.
    -> Try a smaller maximum time.
    -> Move left.

    If required workers > k:
    -> Current maximum time is too small.
    -> Need a larger maximum time.
    -> Move right.

    Time Complexity: O(n * log(sum(arr)))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Answer + Greedy

    low = maximum element
    high = total sum

    Valid -> high = mid - 1
    Invalid -> low = mid + 1

    Important:
    Jobs must be assigned in contiguous order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long summ(vector<int>& arr, int n) {

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        return sum;
    }

    bool isValid(vector<int>& arr, int n, int k, long long mid) {

        int cnt = 1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {

            if (sum + arr[i] > mid) {
                cnt++;
                sum = arr[i];
            }
            else {
                sum += arr[i];
            }
        }

        return cnt <= k;
    }

    int minTime(vector<int>& arr, int k) {

        int n = arr.size();

        if (k > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = summ(arr, n);

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isValid(arr, n, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main() {
    return 0;
}