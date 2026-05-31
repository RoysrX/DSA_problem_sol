class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev = matrix[0];

        for(int i = 1; i < n; i++) {
            vector<int> cur(m);

            for(int j = 0; j < m; j++) {

                int up = matrix[i][j] + prev[j];

                int ld = matrix[i][j];
                if(j > 0) ld += prev[j-1];
                else ld += 1e9;

                int rd = matrix[i][j];
                if(j < m-1) rd += prev[j+1];
                else rd += 1e9;

                cur[j] = min(up, min(ld, rd));
            }

            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};