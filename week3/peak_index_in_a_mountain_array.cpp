////////////////
// Iterative  //
////////////////

class Solution {
public:

    // time O(n) bc loop through all nums in array 
    // space O(1)
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int res; 
        
        for (int i = 0; i < n - 1; i++) { 
            if (A[i] > A[i+1]) {
                res = i;
                break; 
            }
        }
        
        return res; 
    }
};

///////////////////
// Binary Search //
///////////////////

// Mid leans toward left
class Solution {
public:
    // time O(logn)
    // space O(1) 
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1; 
        
        while (left != right) {
            // left + right could be too big for integer 
            // so don't use (left + right) / 2
            int mid = left + (right - left) / 2; 
            
            if (A[mid] < A[mid+1])
                // 4 5 6 peak on right 
                left = mid + 1; 
            else
                // 6 5 4 peak on left 
                right = mid; 
        }
        
        return left; 
    }
};

// Mid leans toward right 
class Solution {
public:
    // time O(logn)
    // space O(1) 
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1; 
        
        while (left != right) {
            // left + right could be too big for integer 
            // so don't use (left + right) / 2
            // use + 1 at end to lean right 
            int mid = left + (right - left) / 2 + 1; 
            
            if (A[mid] > A[mid-1])
                // 4 5 6 peak on right 
                left = mid; 
            else
                // 6 5 4 peak on left 
                right = mid - 1; 
        }
        
        return left; 
    }
};