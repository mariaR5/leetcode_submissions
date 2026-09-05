class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) return nums[i];
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i-2, nums, dp);
        int nonPick = 0 + f(i-1, nums, dp);

        return dp[i] = max(pick, nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // return f(n - 1, nums, dp);

        dp[0] = nums[0];

        if (n > 1)
            dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i-2];
            int nonPick = 0 + dp[i-1];

            dp[i] = max(pick, nonPick);
        }

        return dp[n-1];
    }
};