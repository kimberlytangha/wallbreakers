class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string hold;
        backtrack(n, n, hold, ans);
        return ans;
    }
    
    void backtrack(int o, int c, string hold, vector<string> &ans) {
        cout << hold << endl;
        
        if (o < 0 || c < 0 || o > c) 
            // means you have an imbalanced set of parens 
            // so prune this part of the tree
            return;
        if (o == 0 && c == 0) {
            // balanced set of parens so add 
            cout << "adding " << hold << endl;
            ans.push_back(hold);
        }
        
        // always start with recursive on open paren
        backtrack(o-1, c, hold + '(', ans);
        // then add close paren 
        backtrack(o, c-1, hold + ')', ans);
    }
};
