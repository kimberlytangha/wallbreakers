// problem is VERY similar idea to number of islands (leetcode #200)

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int numCircles = 0; 
        
        // create vector of people visited 
        vector<int> visited(M.size(), 0);
        
        for (int row = 0; row < M.size(); row++) {
            if (!visited[row]) {
                numCircles++; 
                
                dfs(M, visited, row);
                // when dfs completes, you have found all 
                // people in a friend group, so continue to next row
                // note that visited friends will be 
                // marked as visited; very similar to leetcode #200 
                // in this sense
            }
        }
        
        return numCircles;
    }
    
    void dfs(vector<vector<int>>& M, vector<int> &visited, int row) {
        // mark current person so you don't dfs again 
        visited[row] = 1; 
        
        for (int col = 0; col < M.size(); col++) {
            if (!visited[col] && M[row][col]) {
                // first part checks that you haven't 
                // visited this person already 
                // second part checks link exists 
                // (M at row, col is 1)
                
                // mark person as visited 
                visited[col] = 1;
                
                // jump to neighbor or next row until 
                // you run out of neighbors to check 
                dfs(M, visited, col); 
            }
        }
    }
};