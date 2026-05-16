class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r=0;
        int l=0;
        int maxLen =0;
        int n = nums.size();
        while(r  < nums.size()){
            while(nums[r] > 1LL * nums[l] * k){
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return n-maxLen;
    }
};