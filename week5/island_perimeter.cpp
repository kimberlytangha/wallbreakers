class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) 
            return 0; 
        
        int rows = grid.size();
        int cols = grid[0].size(); 
        int perm = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // traverse grid if it's 1 
                
                // add to local if you're at the last/beginning row or col 
                // add also or if you land on a 0
                if (grid[r][c] == 1) {
                    int local = 0;    
                    // r==0 bc you know you're at the top row so you have border 
                    if (r == 0 || grid[r-1][c] == 0) perm++;
                    
                    // r == grid.size()-1 bc you know you're at the bottom row
                    if (r == grid.size()-1 || grid[r+1][c] == 0) perm++;
                    
                    //  grid[0].size()-1 bc you know you're at the last col so you have border 
                    if (c == grid[0].size()-1 || grid[r][c+1] == 0) perm++;
                    
                    // c==0 bc you know you're at the first col so you have border 
                    if (c == 0 || grid[r][c-1] == 0) perm++;
                    perm += local; 
                }
            }
        }
        
        return perm; 
    }

};