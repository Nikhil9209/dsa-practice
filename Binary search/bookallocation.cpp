/*
    Problem: Allocate Minimum Pages

    Topic: Binary Search

    Pattern: Binary Search on Answer + Greedy

    Optimal Approach:
    Use Binary Search on Answer.

    Search Range:
    low = maximum pages in a single book
    high = total pages of all books

    For a particular mid:
    Greedily allocate consecutive books to each student
    until adding the next book would exceed mid.

    If required students <= k:
    -> Current maximum pages is possible.
    -> Try a smaller maximum.
    -> Move left.

    If required students > k:
    -> Current maximum is too small.
    -> Need a larger maximum.
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
    Books must be allocated in contiguous order.
    One book cannot be split between students.
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

    bool validans(vector<int>& arr, long long mid, int k) {

        long long sum = 0;
        int cnt = 1;

        for (int i = 0; i < arr.size(); i++) {

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

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        if (k > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = summ(arr, n);

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (validans(arr, mid, k)) {
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