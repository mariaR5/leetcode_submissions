class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        priority_queue<int> ready;
        queue<pair<int, int>> wait;

        int time = 0; 

        for (char task: tasks)
            mpp[task]++;
        
        for (auto el: mpp)
            ready.push(el.second);
        
        while(!ready.empty() || !wait.empty()) {
            if (!wait.empty() && wait.front().second == time) {
                ready.push(wait.front().first);
                wait.pop();
            }

            if (!ready.empty()) {            
                int topTask = ready.top();
                ready.pop();
                topTask--;
                if (topTask > 0)
                    wait.push({topTask, time + n + 1});
            }
            
            time++;
        }

        return time;
    }
};