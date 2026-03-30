class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int m = 1e9 + 7;
        int n = nums.size();

        vector<int> power(n);
        power[0] = 1;

        // FIXED LOOP
        for(int i = 1; i < n; i++){
            power[i] = (power[i-1] * 2) % m;
        }

        int l = 0, r = n - 1;
        int res = 0;

        while(l <= r){
            if(nums[l] + nums[r] <= target){
                int diff = r - l;
                res = (res + power[diff]) % m;
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};