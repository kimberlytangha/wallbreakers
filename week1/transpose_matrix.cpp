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