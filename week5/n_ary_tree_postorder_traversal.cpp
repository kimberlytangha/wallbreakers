////////////////////////
// Recursive Approach //
////////////////////////
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res; 
        
        traverse(root, res);
        
        return res; 
    }
    
    // Post order L, R, Root 
    void traverse(Node *curr, vector<int> &res) {
        if (!curr)
            return;
        
        if (!curr->children.empty()) {
            // traverse all children
            for (Node* c : curr->children) {
                traverse(c, res);
            }    
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
        
        // use stk to keep track of children nodes 
        stack<Node*> siblings; 
        siblings.push(root);
        
        vector<int> res;
        
        while (!siblings.empty()) {
            Node *curr = siblings.top();
            
            // pop so children can go on top 
            siblings.pop(); 
            
            for (Node *c : curr->children) 
                siblings.push(c);
            
            res.push_back(curr->val); 
        }
        
        // reverse the list 
        reverse(res.begin(), res.end());
        return res; 
    }
};