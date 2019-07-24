// 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1; 
        vector<int> seq2;
        
        dfs(root1, seq1);
        dfs(root2, seq2);
        
        return seq1 == seq2; 
    }
    
    void dfs(TreeNode *curr, vector<int> &seq) {
        if (!curr->left && !curr->right) {
            seq.push_back(curr->val);
            return;
        }
        
        if (curr->left) {
            dfs(curr->left, seq); 
        }
        
        if (curr->right) {
            dfs(curr->right, seq);     
        }
        
    }
};

// found in discussions 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1; 
        stack<TreeNode*> stk2;
        stk1.push(root1);
        stk2.push(root2);
        
        // ensure the stack is empty
        while (!stk1.empty() && !stk2.empty()) {
            if (findLeaf(stk1) != findLeaf(stk2)) {
                return false;
            }
        }
        
        return true;
    }
    
    int findLeaf(stack<TreeNode*>& stk) {
        while (true) {
            TreeNode *top = stk.top();
            stk.pop();
            
            // add right, then left to stack 
            // so check from left to right
            if (top->right) {
                stk.push(top->right);
            } 
            
            if (top->left) {
                stk.push(top->left);
            }
            
            if (!top->left && !top->right) {
                return top->val; 
            }
        }

    }
};