// time O(N) bc we need to visit each node 
// space O(H) bc call stack would be H layers deep due to recursion 
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxPath = 0; 
        findDup(root, maxPath); 
        return maxPath;
    }
    
    int findDup(TreeNode *node, int &maxPath) {
        if (!node)
            return 0; 
        
        int l = findDup(node->left, maxPath);
        int r = findDup(node->right, maxPath);
        
        if (node->left && node->left->val == node->val)
            l += 1;         // chain continues
        else
            l = 0;          // reset to 0 if the chain breaks
       
        
        if (node->right && node->right->val == node->val)
            r += 1;         // chain continues
        else
            r = 0;          // reset to 0 if the chain breaks
        
        // update the longest path value
        maxPath = max(maxPath, r + l);

        // for a given node, want to know which child had longest 
        // univalue path 
        return max(r, l);
    }
    
};