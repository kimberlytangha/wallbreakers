class Solution {
public:
    // time O(n*m)
    // space O(1)
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size(); 
        
        for (int i = 0; i < rows; i++) {
            int k = cols - 1; 
            
            for (int j = 0; j <= k; j++, k--) {
                if (j != k) {
                    swap(A[i][j], A[i][k]);    
                    // ^ inverts bit 
                    A[i][k] ^= 1;
                }
                
                // need to keep out of if incase j & k end at same pos
                // don't want to XOR or invert twice
                A[i][j] ^= 1;
            }
        }
        
        return A; 
    }
};