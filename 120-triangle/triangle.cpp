class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == 0) return triangle[0][0];

        if (dp[i][j] != -1) return dp[i][j];

        int first = INT_MAX;
        int second = INT_MAX;

        if (j < i)
            first = triangle[i][j] + f(i-1, j, triangle, dp);
        if (j > 0)
            second = triangle[i][j] + f(i-1, j-1, triangle, dp);

        return dp[i][j] = min(first, second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            ans = min(ans, f(m-1, i, triangle, dp));
        }

        return ans;
    }
};