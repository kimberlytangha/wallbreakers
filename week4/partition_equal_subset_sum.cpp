class Solution {
public:
    // Goal is to dfs through input until half reaches 0 or below.
    // Half represents a "tally" of what elements you checked and how those
    // bring you closer to the half-half partition. 
    
    // if half dips below zero, you PRUNE that part of the tree
    // if half is 0, you have found one solution so return true
    vector<int> nums; 
    int n; 
    
    bool canPartition(vector<int>& input) {
        // set global variables to access in helper function 
        nums = input; 
        n = nums.size();
        
        if (n == 0) 
            return false; 
        
        int total = 0; 
        for (int k : nums) 
            total += k;
        
        // if total is odd — splitting evenly is impossible 
        if (total & 1)
            return false;
        
        // sort in descending order
        sort(nums.begin(), nums.end(), mySort);
        
        int half = total / 2; 
        return dfs(half, 0);
    }
    
    bool dfs(int sum, int curr) {
        if (sum == 0) 
            return true; 
        
        for (int i = curr; i < n; i++) {
            // skip over values that bring sum to below 0
            if (nums[i] > sum) 
                continue;
            
            // dfs to find next possible element
            // next dfs has sum reduced by nums[i]
            // start next dfs search at index i+1
            if (dfs(sum-nums[i], i + 1)) 
                return true; 
            
            // skip over duplicate values 
            while (i+1 < n && nums[i] == nums[i+1]) 
                i++; 
        }
        return false; 
    }
    
    static bool mySort(int a, int b) {
        return a > b; 
    }
};