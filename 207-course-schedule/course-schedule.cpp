class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbour: adj[node]) {
            if (!visited[neighbour]) {
                if (isCycle(neighbour, adj, visited, pathVisited)) return true;
            }
            else if (pathVisited[neighbour]) return true;
        }

        pathVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build the graph
        for (auto edge: prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycle(i, adj, visited, pathVisited))
                return false; 
        }
        return true;
    }
};