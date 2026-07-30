class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> mpp;
        int maxi = 0;

        while (right < s.size()) {
            mpp[s[right]]++;

            while (mpp[s[right]] > 1) {
                mpp[s[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};