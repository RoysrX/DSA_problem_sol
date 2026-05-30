class Solution {
public:

    // int sol(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    //     if(n==0 && m==0) return grid[0][0];
    //     if(n < 0 || m < 0 || n >= grid.size() || m >= grid[0].size()) return 10000000;
    //     if(dp[n][m] != -1) return dp[n][m];

    //     int up = grid[n][m] + sol(n-1, m, grid, dp);
    //     int left = grid[n][m] + sol(n, m-1, grid, dp);

    //     return dp[n][m] = min(up, left);
    // }
    
    int solByTabu(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        for(int i =0; i<=n-1; i++){
            for(int j=0 ;j <=m-1; j++){
                if(i==0 && j ==0) dp[i][j] = grid[0][0];
                else{
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solByTabu(n, m, grid, dp);
    }
};