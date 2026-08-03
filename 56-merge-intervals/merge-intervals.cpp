class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            int j = i;
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (j < intervals.size() - 1 && end >= intervals[j + 1][0]){
                j++;
                end = max(end, intervals[j][1]);
            }
            result.push_back({start, end});
            i = j;
        }
        return result;
    }
};