class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int i = 1;
        int count = 0;

        while (i < intervals.size()) {
            if (end > intervals[i][0]) {
                count++;
                end = min(end, intervals[i][1]);
            }
            else end = intervals[i][1];
            i++;
        }

        return count;
    }
};