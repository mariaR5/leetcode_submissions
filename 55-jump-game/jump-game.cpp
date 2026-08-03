class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i <= reachable) {
                reachable = max(reachable, i + nums[i]);
            }
            else return false;
        }
        return true;
    }
};