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

// Redid using two pointer, but slightly diff than above
// Once j is on even element, immediately swap (i, j)
class Solution {
public:
    // time O(n) 
    // space O(1) swapping in place 
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size(); 
        if (n == 1) 
            return A;
        
        // i points to odd
        int i = 0; 
        
        // j points to even 
        int j = 0; 
        while (j < n) {
            if (A[j] % 2 == 0) {
                // found even on wrong side, now swap
                swap(A[i], A[j]);
                i++; 
            }
            j++;
        }
        
        return A; 
    }
};