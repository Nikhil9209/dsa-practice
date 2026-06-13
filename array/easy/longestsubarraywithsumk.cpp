#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int left = 0;
    int sum = 0;
    int len = 0;

    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];

        while(sum > k) {
            sum -= arr[left];
            left++;
        }

        if(sum == k) {
            len = max(len, right - left + 1);
        }
    }

    return len;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestSubarray(arr, k);
}