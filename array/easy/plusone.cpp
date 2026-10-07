class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int carry = 1;
        for(int i = nums.size()-1 ; i>=0; i--)
        {   
            int  sum = nums[i]+carry;
            carry = sum/10;
            nums[i] = sum%10;
            if(carry == 0) break;
        }

        if(carry){
             nums.insert(nums.begin(), carry);
        }

        return nums;
    }
};