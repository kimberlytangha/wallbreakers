// simiar to friend circles problem (leetcode #547) 
class Solution {
public:
    // time is O(??) how to find time for dfs?
    // space is O(1) bc we don't use any additional
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; 
        
        // rows != cols !! 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++; 
                    dfs(grid, i, j); 
                }
            }
        }
        
        return count; 
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        // return if out of bounds or don't have land on (row,col)
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || 
            grid[row][col] == '0') {
            return;
        }

        // mark as visited to prevent dfs on (row,col) in future
        grid[row][col] = '0';   
        
        // visit north, south, east, west 
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
};