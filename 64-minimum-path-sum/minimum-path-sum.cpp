class Solution {
public:

    int sol(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(n==0 && m==0) return grid[0][0];
        if(n < 0 || m < 0 || n >= grid.size() || m >= grid[0].size()) return 10000000;
        if(dp[n][m] != -1) return dp[n][m];

        int up = grid[n][m] + sol(n-1, m, grid, dp);
        int left = grid[n][m] + sol(n, m-1, grid, dp);

        return dp[n][m] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return sol(n-1, m-1, grid, dp);
    }
};