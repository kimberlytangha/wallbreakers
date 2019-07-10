class Solution {
public:
    // time O(logn)
    // space O(1)
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1; 
        
        // <= needed for array of size 1
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (target > nums[mid]) {
                left = mid + 1; 
            } else if (target < nums[mid]) {
                right = mid - 1; 
            } else {
                return mid; 
            }
        }
        
        return -1; 
    }
};