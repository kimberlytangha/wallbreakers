class Solution {
public:
    int maxD; 
    
    // time O(n)    
    // space O(1)
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return maxD;
    }
    
    int traverse(TreeNode *curr) {
        if (!curr) {
           return 0;
        }
        
        int leftLen = traverse(curr->left);
        int rightLen = traverse(curr->right); 
        
        if (leftLen + rightLen > maxD) 
            maxD = leftLen + rightLen;
        
        // return max between left and right subtrees
        // important bc we need to know longest depth 
        // at every junction/ node 
        return max(++leftLen, ++rightLen);
    }
};