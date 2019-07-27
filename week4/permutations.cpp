class Solution {
public:
    vector<int> n; 
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums; 
        
        vector<bool> visited(n.size(), false);
        vector<int> hold;
        vector<vector<int>> ans; 
        
        find(0, visited, hold, ans);
        return ans; 
    }
    
    void find(int depth, vector<bool> v, vector<int> hold, vector<vector<int>> &ans) {
        if (depth == n.size()) {
            ans.push_back(hold);
            return;
        }
        
        for (int i = 0; i < n.size(); i++) {
            if (!v[i]) {
                hold.push_back(n[i]);
                v[i] = true;
                
                // hold: [1] => find goes down one level to permute [1,2] and [1,3]
                find(depth+1, v, hold, ans); 
                
                hold.pop_back();
                v[i] = false;
            }
        }
        
        return; 
    }
};

// similar to last implementation, but saves on 
// space complexity bc we're permuting in place using swap  
class Solution {
public:    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        find(0, nums, ans);
        return ans; 
    }
    
    // swap in place 
    void find(int pivot, vector<int> &nums, vector<vector<int>> &ans) {
        if (pivot == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = pivot; i < nums.size(); i++) {
            // swap pivot with i
            swap(nums[i], nums[pivot]);
            // go down level 
            find(pivot+1, nums, ans); 
            // restore order and go up one level in tree
            swap(nums[pivot], nums[i]);
        }
        
        return; 
    }
};