// very similar to other back tracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> hold;
        backtrack(ans, 0, hold, n, k);
        return ans;
    }
    
    void backtrack(vector<vector<int>>& ans, int begin, vector<int> &hold, int n, int k) {
        if (hold.size() == k) {
            ans.push_back(hold);
            return;
        }
        
        for (int i = begin; i < n; i++) {
            hold.push_back(i+1); 
            // recurse using i+1 not begin+1
            backtrack(ans, i+1, hold, n, k);
            hold.pop_back();
        }
    }
};