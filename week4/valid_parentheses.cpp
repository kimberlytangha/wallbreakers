class Solution {
public:
    // time O(n)
    // space O(n) for stk data structure
    bool isValid(string s) {
        int n = s.size(); 
        
        if (n == 0)
            return true; 
        
        stack<char> stk; 
        
        for (int i = 0 ; i < n; i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    char top = stk.top(); 
                    if (top == '[' && s[i] == ']') {
                        stk.pop(); 
                    } else if (top == '{'  && s[i] == '}') {
                        stk.pop(); 
                    } else if (top == '('  && s[i] == ')') {
                        stk.pop(); 
                    } else {
                        return false; 
                    }
                } else {
                    return false; 
                }
            }
        }
 
        return stk.empty();
    }
};


// Slightly cleanier solution 
class Solution {
public:
    // time O(n)
    // space O(n) for stk data structure
    bool isValid(string s) {
        int n = s.size(); 
        if (n == 0)
            return true; 
        
        stack<char> stk; 
        
        for (int i = 0 ; i < n; i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                stk.push(s[i]);
            } else {
                if (!stk.empty() && stk.top() == '[' && s[i] == ']') {
                    stk.pop(); 
                } else if (!stk.empty() && stk.top() == '{' && s[i] == '}') {
                    stk.pop(); 
                } else if (!stk.empty() && stk.top() == '(' && s[i] == ')') {
                    stk.pop(); 
                } else {
                    return false;  
                }
            }
        }
 
        return stk.empty();
    }
};