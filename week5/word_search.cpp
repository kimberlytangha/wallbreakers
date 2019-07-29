// not best solution 
class Solution {
public:
    
    int n;
    string w; 
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size(); 
        n = word.size(); 
        w = word; 
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // cout << r << " " << c << endl;
                string builder; 
                if (search(board, r, c, builder, 0)) return true;
            }
        }
        
        return false; 
    }
    
    bool search(vector<vector<char>>& board, int r, int c, string b, int ptr) {
        // check for out of bounds/ visited
        if (isInvalid(board, r, c)) {
            // cout << "invalid input " << r << " " << c << endl;
            return false; 
        }
        
        // mark as visited 
        char tmp = board[r][c];
        board[r][c] = '#';
        
        // answer
        bool res = false; 
        
        // append to builder or return if not possible 
        if (tmp == w[ptr]) {
            b += tmp;  
            // cout << b << " " << w << endl;
            
            cout << b.length() << " " << n << endl;
            if (b.length() == n) {
                // cout << "returning true" << endl;
                return true; 
            } else {
                // use one statement for dfs into word search
                res = search(board, r+1, c, b, ptr+1) || 
                    search(board, r-1, c, b, ptr+1) || 
                    search(board, r, c+1, b, ptr+1) || 
                    search(board, r, c-1, b, ptr+1);  
            }           
        } 

        // need to change word back to what it was prior 
        board[r][c] = tmp; 
        
        return res; 
    }
    
    bool isInvalid(vector<vector<char>>& board, int r, int c) {
        return (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || 
                 board[r][c] == '#'); 
            
    }
};

// can also just pass integer to reference which 
// part of word you're checking with the board[r][c]
class Solution {
public:
    
    int n;
    string w; 
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size(); 
        n = word.size(); 
        w = word; 
        
        for (int r = 0; r < rows; r++) 
            for (int c = 0; c < cols; c++) 
                if (search(board, r, c, word)) return true;
        
        return false; 
    }
    
    bool search(vector<vector<char>>& board, int r, int c, string wd) {
        if (wd.length() == 0) 
            return true; 
        
        // check for out of bounds/ visited
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || 
                 wd[0] != board[r][c]) {
            return false; 
        }
        
        char tmp = board[r][c]; 
        board[r][c] = '#';
        
        // wd.substr(1) => copies everything but first char in word
        bool res = search(board, r-1, c, wd.substr(1)) ||
            search(board, r+1, c, wd.substr(1)) ||
            search(board, r, c-1, wd.substr(1)) ||
            search(board, r, c+1, wd.substr(1));
        
        board[r][c] = tmp; 
        return res; 
    }
};
