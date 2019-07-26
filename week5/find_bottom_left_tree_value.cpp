// use map to keep track of left-most leaf node per level
// time O(n)
// space O(n) for hm 
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;
        
        // map is <level, nodeVal> 
        unordered_map<int, int> bucket;
        dfs(root, 0, bucket);
        
        int nodeVal; 
        
        // find lowest depth node
        int maxDepth = 0; 
        for (auto item : bucket) {
            if (item.first > maxDepth) {
                maxDepth = item.first;
                nodeVal = item.second; 
            }
        }
        
        return nodeVal; 
    }
    
    void dfs(TreeNode *curr, int d, unordered_map<int, int> &bucket) {
        if (!curr) 
            return; 
        
        dfs(curr->left, d+1, bucket);
        dfs(curr->right, d+1, bucket);
        
        if (!curr->left && !curr->right && bucket.find(d) == bucket.end()) {
            bucket[d] = curr->val; 
        }
    }
};