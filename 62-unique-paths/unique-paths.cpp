class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int right = 0, down = 0;
        
        if (i > 0)
            right = f(i-1, j, dp);
        
        if (j > 0)
            down = f(i, j-1, dp);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(m-1, n-1, dp);

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                int right = 0, down = 0;

                if (i > 0) right = dp[i-1][j];
                if (j > 0) down = dp[i][j-1];

                dp[i][j] = right + down;
            }
        }

        return dp[m-1][n-1];
    }   
};