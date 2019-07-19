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
                
                find(depth+1, v, hold, ans);
                
                // going back up tree
                v[i] = false; 
                hold.pop_back(); 
            }
        }
        
        return; 
    }
};

// similar to last implementation, but saves on space complexity bc we're performing swap 
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        recursive(num, ans, 0);
        return ans;
    }
    
    void recursive(vector<int> &num, vector<vector<int>> &ans, int depth)   {
        if (depth >= num.size()) {
            // cout << "add vector: ";
            // for (int i : num) {
            //     cout << i << " ";
            // }
            // cout << endl;
            ans.push_back(num);
            return;
        }
        
        for (int i = depth; i < num.size(); i++) {
            // cout << num[depth] << " " << num[i] << endl;
            swap(num[depth], num[i]);
            recursive(num, ans, depth + 1);     
            // restore order and go up one level in tree
            swap(num[depth], num[i]);
        }
    }
};