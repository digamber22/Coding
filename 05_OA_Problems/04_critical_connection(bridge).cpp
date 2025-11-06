class Solution {
public:
// TC -> O(V + E), SC -> O(V) 
// using tarjan's algo

    int timer = 1;
    vector<int> tin, low;
    vector<vector<int>> bridges;  // store answers

    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (vis[it] == 0) {

                dfs(it, node, vis, adj);
                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    bridges.push_back({node, it}); // store bridge
                }
            } 
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n); 

        for (auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        tin.assign(n, 0);
        low.assign(n, 0);
        bridges.clear();

        for (int i = 0; i < n; ++i) 
        if (!vis[i]) dfs(i, -1, vis, adj); // run DFS for all components
        
        return bridges;
    }
};

