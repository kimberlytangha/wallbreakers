// Idea is you want to contiually take the 
// max of these two inputs
// f(k) = max( f(k-2) + nums[k], f(k-1) )
class Solution {
public:
    // time O(n)
    // space O(1)
    int rob(vector<int>& nums) {
        int f1 = 0;           
        int curr = 0;           // holds maxProfit
        
        for (int num : nums) {
            int f2 = f1;        // f2 is f[k-2] value
            f1 = curr;          // f1 is f[k-1]
            
            // plug into formula above
            curr = max(f2 + num, f1); 
        }
        
        return curr; 
    }
};