class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto edge: times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while(!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();

            if (curDist > dist[node]) continue;

            for (auto [neighbour, weight]: adj[node]) {
                if (curDist + weight < dist[neighbour]) {
                    dist[neighbour] = curDist + weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            answer = max(answer, dist[i]);
        }

        return answer;
    }
};