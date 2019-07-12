///////////////
// Recursive //
///////////////

class Solution {
public:
    // Solution uses the following proof and idea that we can 
    // either use or not use the first element in the array 
    // since it has a circular shape
    // 
    // f(k) = max( f(k-2) + nums[k], f(k-1) )
    // See house_robber_i.cpp as well 
    int rob(vector<int>& nums) {
        if (nums.empty()) 
            return 0; 
        else if (nums.size() == 1)
            return nums[0];

        // find solution for array without first element
        vector<int> noFirst (nums.begin() + 1, nums.end());
        vector<int> res1 = recursion(noFirst); 
        int max1 = max(res1[0], res1[1]);
        
        // find solution for array without last element
        vector<int> noLast (nums.begin(), nums.end()-1);
        vector<int> res2 = recursion(noLast); 
        int max2 = max(res2[0], res2[1]);
        
        // return the max profit 
        return max(max1, max2);
    }
    
    vector<int> recursion(vector<int>& nums) {
        if (nums.empty()) 
            return {0,0}; 
        
        // reduce size of nums by removing first element of nums
        vector<int> smallerNums (nums.begin() + 1, nums.end());
        vector<int> previous = recursion(smallerNums);
        
        vector<int> res = {0, 0}; 
        
        // f(k-2) + nums[k]
        res[0] = nums[0] + previous[1];

        // f(k-1)
        res[1] = max(previous[0], previous[1]);
        
        return res; 
    }
};