#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> nums) {
unordered_map<int,int>mpp;
vector<int>ans;
for(int i =0;i<nums.size();i++){
    mpp[nums[i]]++;
}
for(auto it:mpp){
    if(it.second ==0){
        ans.push_back(it.first);
    }
    else if(it.second==2){
        ans.push_back(it.first);
    }
}
return ans;
}
int main (){
    vector<int>arr;
    int n ;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans = findMissingRepeatingNumbers(arr);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i];
    }

}
