class Solution {
public:
    // Idea is to check binary from 0..2^n to see if 
    // an element belongs or does not belong in a given subset
    
    // time O(n*m)
    // space O(n^2)
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // int numSubs = pow(2, n);
        int numSubs = 1 << n;
        vector<vector<int>> res(numSubs);
        
        // outer loops through each array in res
        for (int i = 0; i < numSubs; i++) {
            // loops through each element in nums
            for (int j = 0; j < n; j++ ) {
                // determine if array should have nums[i]
                if ((1 << j) & i) 
                    res[i].push_back(nums[j]);
            }    
        }
        
        return res; 
    }
};