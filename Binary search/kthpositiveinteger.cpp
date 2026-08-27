/*
    Problem: Kth Missing Positive Number

    Topic: Binary Search

    Pattern: Binary Search on Missing Count

    Brute Force:
    Start from 1 and keep checking which positive numbers
    are missing until the kth missing number is found.

    Time Complexity: O(n + k)
    Space Complexity: O(1)

    Optimal Approach:
    Use Binary Search.

    For an index mid:
    
    missing = arr[mid] - (mid + 1)

    Why?
    If there were no missing numbers:
    arr[mid] should be (mid + 1).

    The difference tells us how many positive numbers
    are missing before arr[mid].

    If missing < k:
    -> We need more missing numbers.
    -> Move right.

    If missing >= k:
    -> kth missing number is on the left.
    -> Move left.

    After binary search:
    high points to the last position where
    missing numbers are less than k.

    Answer:
    k + high + 1

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Key Learning:
    Missing numbers before index i:
    arr[i] - (i + 1)

    missing < k  -> move right
    missing >= k -> move left
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return k + high + 1;
    }
};

int main() {
    return 0;
}