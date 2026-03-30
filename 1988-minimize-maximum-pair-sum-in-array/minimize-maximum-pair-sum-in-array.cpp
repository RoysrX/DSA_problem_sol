class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxi=0;
        int l= 0;
        int r= nums.size()-1;
        while(l < r){
            int val = nums[l] + nums[r];
            l++;
            r--;
            maxi = max(maxi, val);
        }
        return maxi;
    }
};