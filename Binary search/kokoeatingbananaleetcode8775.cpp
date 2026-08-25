/*
    Problem: Koko Eating Bananas

    Topic: Binary Search

    Pattern: Binary Search on Answer
    Optimal Approach:
    Use Binary Search on the eating speed.

    Search range:
    low = 1
    high = maximum pile

    For every speed, calculate the total hours required.

    If totalH <= h:
    -> Current speed is possible.
    -> Store it as a possible answer.
    -> Try a smaller speed.

    If totalH > h:
    -> Speed is too slow.
    -> Increase the speed.

    Time Complexity: O(n * log(maxPile))
    Space Complexity: O(1)

    Key Learning:
    Binary Search on Answer

    Condition:
    speed works if totalHours <= h

    Works -> move left
    Doesn't work -> move right

    Ceiling Division:
    (piles[i] + speed - 1) / speed
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long calculateTotalHours(vector<int>& piles, int speed) {

        long long totalH = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalH += (piles[i] + (long long)speed - 1) / speed;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int maxPile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxPile;
        int ans = maxPile;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
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