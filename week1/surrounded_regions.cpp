class Solution {
public:
    // time O(n*m) i think for loop + dfs through board
    // space O(n*m) for flip board storage 
    vector<vector<char>> flip;
    vector<vector<char>> origB;
    
    // Two boards (original and flip board) used to cross reference
    // DFS through edges of board to find where to flip  
    // indiciate on flip board 'O' for no flip
    // Reference flip board for 'O' and flip corresponding on orig board
    void solve(vector<vector<char>>& board) {
        int rows = board.size(); 
        if (!rows) 
            return; 
        
        int cols = board[0].size();
        if (!cols)
            return;
        
        // contains X for locations to flip; O for don't flip
        vector<vector<char>> f(rows, vector<char>(cols, 'X'));
        flip = f; 
        origB = board; 
        
        // Check edges ONLY for 'O' that should not be flipped
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                if ((i == 0 || i == rows-1) && board[i][k] == 'O') 
                    dfs(i,k);
                
                if ((k == 0 || k == cols-1)  && board[i][k] == 'O') 
                    dfs(i,k);  
            }
        }
        
        
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                // Slight speed up so we don't touch 
                // parts of original board that are not 'O'
                if (board[i][k] == 'X') 
                    continue; 
                
                // Checks flip board to see which spot 
                // to flip denoted by 'X'
                if (flip[i][k] == 'X') 
                    board[i][k] = 'X';
            }
        }
    }
    
    // dfs on board to find where to NOT flip and marks those with 'O'
    void dfs(int i , int k) {
        if (i < 0 || k < 0 || i >= flip.size() || k >= flip[0].size() || 
            origB[i][k] == 'X' || flip[i][k] == 'O') 
            return;
        
        flip[i][k] = 'O';
        
        dfs(i+1, k);
        dfs(i-1, k);
        dfs(i, k+1);
        dfs(i, k-1);
    }
};