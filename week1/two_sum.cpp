class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        vector<int> res; 
        
        // time O(n) - need to loop through all elements in nums
        // space O(n) - n depends number on KVP stored in map
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
           
            // find takes O(1) unless in worst case performs linear search O(n)
            if (mp.find(comp) != mp.end()) {
                res = {i, mp[comp]};
            } else {
                // [] takes O(1) unless in worst case performs linear search O(n)
                mp[nums[i]] = i; 
            }
        }
        return res; 
    }
};