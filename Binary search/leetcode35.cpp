/*
    Problem: Search Insert Position
    Topic: Binary Search
    Pattern: Lower Bound
    Time Complexity: O(log n)
    Space Complexity: O(1)
    Similiar question : lowerbound
*/



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int ans = nums.size();
        while(left <= right){
           int  mid = left +(right-left)/2;
            if(nums[mid]>=target){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1; 

        }
        return ans;
    }
};
int main(){
    return 0;
}