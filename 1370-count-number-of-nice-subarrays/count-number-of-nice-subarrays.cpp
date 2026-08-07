class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int subCount = 0;
        int oddCount = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) oddCount++;

            while (oddCount > k) {
                if (nums[left] % 2 == 1) oddCount--;
                left++;
            }

            subCount += right - left + 1;
        }

        return subCount;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};