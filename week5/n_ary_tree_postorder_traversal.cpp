////////////////////////
// Recursive Approach //
////////////////////////
class Solution {
public:
    // time O(n)
    // space O(m) - for leaf val vector 
    vector<int> postorder(Node* root) {
        vector<int> res; 
        traverse(root, res);
        return res; 
    }
    
    void traverse(Node *curr, vector<int> &res) {
        if (!curr)
            return;
        
        // traverse all children
        for (Node *c : curr->children) {
            traverse(c, res);
        }
        
        // add current node            
        res.push_back(curr->val); 
    
    }
};

////////////////////////
// Iterative Approach //
////////////////////////
// use stack to perform pre-order traversal, but reverse res to get
// a post-order print out of nodes 
// [1,4,2,3,6,5] which adds starting from the right, moving leftward
// [5,6,3,2,4,1] reverse the first array and you get this 
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {}; 
        
        vector<int> res; 
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            Node *n = stk.top();
            stk.pop();
            
            // add all children in reverse order
            for (Node* c : n->children)
                stk.push(c); 
            
            // add node value to results array 
            res.push_back(n->val); 
        }
        
        reverse(res.begin(), res.end());
        return res; 
    }
};