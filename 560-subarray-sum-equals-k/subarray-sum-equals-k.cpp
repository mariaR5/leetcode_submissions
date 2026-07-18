class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> mpp;

        mpp[0] = 1;

        for(int num: nums) {
            sum += num;

            if (mpp.find(sum - k) != mpp.end())
                count += mpp[sum - k];
            
            mpp[sum]++;
        }
        return count;
    }
};