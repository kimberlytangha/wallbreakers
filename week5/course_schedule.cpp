// question is really asking if the graph is cyclic or not
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        
        // visited node has 3 states: 
        // 0 inital state 
        // -1 visited during a dfs
        // 1 to denote dfs completely   
        vector<int> v(numCourses, 0);

        for (int i = 0; i < numCourses; i++) 
            if (!completeDFS(g, v, i)) return false;
        
        return true;
    }
    
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) 
            // sort by second element  
            g[p[1]].push_back(p[0]);
        return g;
    }
    
    bool completeDFS(graph& g, vector<int>& v, int node) {
        // already visited in dfs
        if (v[node] == -1) return false;
        
        // successfully completed acyclical dfs for this node already
        if (v[node] == 1) return true;
        
        // mark as visited 
        v[node] = -1;
        
        // dfs through children nodes 
        for (int i: g[node]) 
            if (!completeDFS(g, v, i)) return false;

        // reset visited nodes 
        v[node] = 1;
        return true;
    }
};