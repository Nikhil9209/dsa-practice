/*
    Pattern: Binary Search
    Approach:
    Use binary search.
    If arr[mid] == target, both floor and ceil are target.
    If arr[mid] < target, arr[mid] can be the floor,
    so search on the right for a larger possible floor.
    If arr[mid] > target, arr[mid] can be the ceil,
    so search on the left for a smaller possible ceil.
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> findFloorCeil(const vector<int>& arr, int k) {

        int left = 0;
        int right = arr.size() - 1;

        int fl = -1;
        int cl = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == k) {
                return {k, k};
            }

            else if (arr[mid] < k) {
                fl = arr[mid];
                left = mid + 1;
            }

            else {
                cl = arr[mid];
                right = mid - 1;
            }
        }

        return {fl, cl};
    }
};

int main() {
    return 0;
}