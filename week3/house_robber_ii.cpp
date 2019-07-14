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

/////////////////////////
// Dynamic Programming //
/////////////////////////
class Solution {
public:
    // Applies same logic as recursive solution 
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 0) 
            return 0; 
        else if (n == 1)
            return nums[0]; 
        
        vector<int> noFirst(nums.begin() + 1, nums.end());
        int profit1 = checkHomes(noFirst);
        
        vector<int> noLast(nums.begin(), nums.end() - 1);
        int profit2 = checkHomes(noLast);
        
        return max(profit1, profit2);
    }
    
    // See house_robber_i.cpp
    // Based on f(k) = max( f(k-2) + nums[k], f(k-1) )
    int checkHomes(vector<int> &nums) {
        int p1 = 0;
        int p2 = 0;
        int curr = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            p2 = p1;            // f(k-2)
            p1 = curr;          // f(k-1)
            curr = max(p2 + nums[i], p1);
        }
        
        return curr; 
    }
};