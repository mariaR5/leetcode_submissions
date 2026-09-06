class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0];

        int up = INT_MAX;
        int left = INT_MAX;

        if (dp[i][j] != -1) return dp[i][j];

        if (i > 0)
            up = grid[i][j] + f(i-1, j, grid, dp);
        if (j > 0)
            left = grid[i][j] + f(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, INT_MAX);
        
        dp[0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int up = dp[j];
                int left = (j > 0) ? dp[j-1] : INT_MAX;

                dp[j] = grid[i][j] + min(up, left);
            }
        }

        return dp[n-1];
    }
};