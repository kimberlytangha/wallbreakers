class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0; 
        int j = A.size()-1;
        
        // takes O(n) time 
        // takes O(1) space because we are swapping in place 
        while (i < j) {
            if (A[i] % 2 == 0) {
                // skip over even numbers
                i++;
            } else {
                // found odd number on left part of array 
                
                while (A[j] % 2 && i < j) {
                    // have j skip over odd numbers 
                    j--;
                }

                swap(A[i],A[j]);
            }
        }
        
        return A;
    }
};