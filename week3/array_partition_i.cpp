class Solution {
public:
    // time O(nlogn) bc of sorting
    // space O(1) bc no extra space 
    int arrayPairSum(vector<int>& nums) {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        int total = 0; 
        
        for (int i = 0; i < size; i += 2) {
            total += nums[i];
        }
        
        return total; 
    }
};