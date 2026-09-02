/*
    Problem: Kth Element of Two Sorted Arrays

    Topic: Binary Search

    Pattern: Binary Search on Partition

    Brute Force:
    Merge both sorted arrays and find the kth element.

    Time Complexity: O(n + m)
    Space Complexity: O(n + m)

    Optimal Approach:
    Apply binary search on the smaller array.

    Partition both arrays such that:

        cut1 + cut2 = k

    left1 = largest element on the left side of array a
    left2 = largest element on the left side of array b

    right1 = smallest element on the right side of array a
    right2 = smallest element on the right side of array b

    Valid partition:
        left1 <= right2
        left2 <= right1

    If the partition is valid:
    -> kth element = max(left1, left2)

    If left1 > right2:
    -> cut1 is too far right
    -> Move left

    Otherwise:
    -> cut1 is too far left
    -> Move right

    Time Complexity: O(log(min(n, m)))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Partition

    Always binary search on the smaller array.

    Partition:
        cut1 + cut2 = k

    Valid:
        left1 <= right2 && left2 <= right1

    Answer:
        max(left1, left2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int kthElement(vector<int>& a, vector<int>& b, int k) {

        // Always binary search on the smaller array
        if (a.size() > b.size()) {
            return kthElement(b, a, k);
        }

        int n = a.size();
        int m = b.size();

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {

            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0)
                        ? INT_MIN
                        : a[cut1 - 1];

            int left2 = (cut2 == 0)
                        ? INT_MIN
                        : b[cut2 - 1];

            int right1 = (cut1 == n)
                         ? INT_MAX
                         : a[cut1];

            int right2 = (cut2 == m)
                         ? INT_MAX
                         : b[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            }

            // cut1 is too far right
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            // cut1 is too far left
            else {
                low = cut1 + 1;
            }
        }

        return 0;
    }
};

int main() {
    return 0;
}