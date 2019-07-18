class Solution {
public:
    // time O(n)
    // space O(n) for stack 
    int scoreOfParentheses(string S) {
        stack<int> stk;
        stk.push(0); 
        
        for (char c : S) {
            if (c == '(') {
                stk.push(0);
            } else {
                // have closing paren so need to compute new score
                int prevScore = stk.top(); 
                stk.pop();
                
                int newPoints = 0; 
                if (prevScore > 0)
                    // there is an inner paren, so you need to double it
                    newPoints = prevScore * 2; 
                else
                    // there is NOT an inner paren, so score stays 1
                    newPoints = 1;
                
                // pass new score in
                stk.top() += newPoints; 
                cout << newPoints << endl;
            }
        }
        
        return stk.top();
    }
    
    
};