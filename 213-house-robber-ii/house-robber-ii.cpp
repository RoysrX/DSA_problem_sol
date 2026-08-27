class Solution {
public:


    int memo(vector<int> &nums, vector<int> &dp, int s, int e){
        if(s > e) return 0;
        
        if(dp[s] != -1) return dp[s];

        int ch1 = nums[s] + memo(nums, dp, s+2, e);
        int ch2 = 0 + memo(nums, dp, s+1, e);

        return dp[s] = max(ch1, ch2); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,-1);

        if(n == 1) return nums[0];
        int start1 = 1, end1 = n-1;
        int rob1 = memo(nums, dp1, start1, end1);

        vector<int> dp2(n,-1);
        int start2 = 0, end2 = n-2;
        int rob2 = memo(nums, dp2, start2, end2);

        return max(rob1, rob2);
    }
};