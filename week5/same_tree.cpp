/////////
// BFS //
/////////
class Solution {
public:
    bool isSameTree(TreeNode* left, TreeNode* right) {
        queue<TreeNode*> leftQ; 
        queue<TreeNode*> rightQ; 
        leftQ.push(left);
        rightQ.push(right);
        
        while (leftQ.size() > 0) {
            TreeNode *nodeL = leftQ.front(); 
            TreeNode *nodeR = rightQ.front();
            leftQ.pop();
            rightQ.pop();

            if (nodeL && nodeR && nodeL->val == nodeR->val) {
                // can traverse down further
                leftQ.push(nodeL->left);
                leftQ.push(nodeL->right);

                rightQ.push(nodeR->left);
                rightQ.push(nodeR->right); 
            } else if (!nodeL && !nodeR) {
                // reached leaf for both nodeL and nodeR
                continue;
            } else {
                // one node but not the other so not identical 
                return false; 
            }
        }
        
        return true; 
    }
};

/////////
// DFS //
/////////
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        
        stk1.push(p);
        stk2.push(q); 
        
        // use stk1.empty() bc we can assume that 
        // stk2 will also be empty 
        while (!stk1.empty()) {
            TreeNode *n1 = stk1.top();
            TreeNode *n2 = stk2.top();
            stk1.pop();
            stk2.pop();

            if (n1 && n2 && n1->val == n2->val) {
                // traverse further down tree    
                stk1.push(n1->left);
                stk1.push(n1->right);
                
                stk2.push(n2->left);
                stk2.push(n2->right);
            } else if (!n1 && !n2) {
                // reached leaf so continue 
                continue;
            } else {
                // find imbalance and return false 
                return false; 
            }
        }
        
        return true; 
    }
};

///////////////
// Recursive //
///////////////
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) 
            // want to make sure both are null types 
            // otherwise the trees are not the same
            return p == q; 
        else {
            // call recursively on left branches and right branches 
            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        } 
            
    }
};