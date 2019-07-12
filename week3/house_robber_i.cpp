// iterative solution 
class Solution {
public:
    // f(k) = max( f(k-2) + nums[k], f(k-1) )
    int rob(vector<int>& nums) {
        int prev = 0;           
        int curr = 0;           // holds maxProfit
        
        for (int num : nums) {
            int tmp = prev;     // tmp is nums[i-2]th value
            prev = curr;        // prev is nums[i-1]th value
            
            // plug into formula above
            curr = max(tmp + num, prev); 
        }
        
        return curr; 
    }
};