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

        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) pick += prev2;
            int nonPick = 0 + prev1;

            int cur = max(pick, nonPick);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};