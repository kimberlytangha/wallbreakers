class Solution {
public:
    // time O(n*m) to loop over all elements
    // space O(n*m) to store tranposed vector 
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int origC = A[0].size(); 
        int origR = A.size();
        
        vector<vector<int>> tp(origC, vector<int>(origR, 0)); 
        
        for (int i = 0; i < origR; i++) 
            for (int j = 0; j < origC; j++) 
                tp[j][i] = A[i][j]; 
        
        return tp; 
    }
};

// Redo
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size(); 
        
        vector<vector<int>> tp(cols, vector<int>(rows, 0));

        for (int i = 0; i < cols; i++)
            for (int k = 0; k < rows; k++)
                tp[i][k] = A[k][i];
        
        return tp;
    }
};