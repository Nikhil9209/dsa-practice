class Solution {
public:

    long long multiply(int mid, int n, int m) {

        long long ans = 1;

        for(int i = 0; i < n; i++) {

            ans = ans * mid;

            if(ans > m) {
                return ans;
            }
        }

        return ans;
    }

    int nthRoot(int n, int m) {

        int low = 1;
        int high = m;
        if (m<1){
        return m;
        }

        while(low <= high) {

            int mid = low + (high - low) / 2;

            long long root = multiply(mid, n, m);

            if(root == m) {
                return mid;
            }
            else if(root > m) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};