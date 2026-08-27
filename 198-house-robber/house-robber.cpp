class Solution {
public:

    int memo(vector<int>& nums, vector<int>& dp, int ind) {

        if(ind >= nums.size())
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int ch1 = nums[ind] + memo(nums, dp, ind + 2);
        int ch2 = memo(nums, dp, ind + 1);

        return dp[ind] = max(ch1, ch2);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return memo(nums, dp, 0);
    }
};