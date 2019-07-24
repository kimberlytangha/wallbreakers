// Iterative 
class Solution {
public:
    int sum; 
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return 0; 
        }
        
        sum = 0; 
        if (root->left) {
            findLeaf(root->left, true);    
        }
        
        if (root->right) {
            findLeaf(root->right, false);
        }
        return sum; 
    }
    
    void findLeaf(TreeNode *curr, bool isLeft) {
        if (!curr->left && !curr->right) {
            if (isLeft) {
                sum += curr->val; 
            } return; 
        } 
        
        if (curr->left) {
            findLeaf(curr->left, true);    
        }
        
        if (curr->right) {
            findLeaf(curr->right, false);
        }
    }
};

// Using stack 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right)
            return 0; 
        
        stack<TreeNode *> stk; 
        
        stk.push(root); 
        int sum = 0; 
        
        // dfs on tree
        while(!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            
            if (node->left)  {
                if (!node->left->left && !node->left->right) {
                    // check to see if node->left is a leaf node
                    // if so, add to sum 
                    sum += node->left->val; 
                } else {
                    stk.push(node->left);
                }
            } 
            
            if (node->right) {
                if (node->right->left || node->right->right) {
                    // ensure we don't add right leaf nodes
                    stk.push(node->right); 
                } 
            }
        }
        
        return sum; 
    }
};