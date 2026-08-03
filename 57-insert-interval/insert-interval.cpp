class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        vector<int> interval = newInterval;
        while (i < n && intervals[i][0] <= newInterval[1]) {
            interval[0] = min(interval[0], intervals[i][0]);
            interval[1] = max(interval[1], intervals[i][1]);
            i++;
        }
        res.push_back(interval);

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};