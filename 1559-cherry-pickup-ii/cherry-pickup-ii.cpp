class Solution {
public:

    int rec(vector<vector<int>> &grid,vector<vector<vector<int>>> &dp, int i, int j1, int j2){
        int m = grid[0].size();
        int n = grid.size();
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return INT_MIN;
        if(i == n-1){
            if(j1 == j2) return grid[i][j2];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
            int maxi = 0;
            for(int dj1 = -1; dj1<=1; dj1++){
                for(int dj2 = -1; dj2<=1; dj2++){
                    if(j1 == j2) maxi = max(maxi, grid[i][j1]+rec(grid, dp, i+1, j1+dj1, j2+dj2));
                    else maxi = max(maxi, grid[i][j1]+grid[i][j2]+rec(grid, dp, i+1, j1+dj1, j2+dj2));
                }
            }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return rec(grid, dp, 0, 0, m-1);
    }
};