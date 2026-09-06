class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int up = 0;
        int left = 0;

        if (i > 0 && obstacleGrid[i-1][j] != 1)
            up = f(i-1, j, obstacleGrid, dp);
        
        if (j > 0 && obstacleGrid[i][j-1] != 1)
            left = f(i, j-1, obstacleGrid, dp);
        
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1) return 0;

        vector<int> dp(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (i == 0 && j == 0) dp[j] = 1;
                else {
                    int left = 0;

                    if (j > 0) left = dp[j-1];
                    dp[j] += left;
                }
            }
        }

        return dp[n-1];
    }
};