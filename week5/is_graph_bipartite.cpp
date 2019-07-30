class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // visited array
        // 0    unvisited
        // 1    color 1
        // -1   color 2
        vector<int> v(n, 0);
        
        for (int i = 0; i < n; i++) 
            // v[i] == 0 ensures node hasn't been visited 
            // incase we have disconnected graph 
            if (v[i] == 0 && !validColor(graph, v, 1, i)) 
                return false;
        
        return true; 
    }
    
    bool validColor(vector<vector<int>>& g, vector<int> &v, int color, int node) {
        if (v[node] != 0)               
            // if visited, check if its color matches 
            // the designated color 
            return v[node] == color; 
        
        v[node] = color; 
        
        for (int next: g[node]) 
            // continue dfs using flipped color 
            if (!validColor(g, v, -color, next)) return false;
        
        return true; 
    }
};