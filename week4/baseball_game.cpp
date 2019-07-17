class Solution {
public:
    // time O(n) for looping through 
    // space O(n) for stk
    int calPoints(vector<string>& ops) {
        if (ops.empty()) 
            return 0; 
        
        stack<int> pts; 
        int total = 0; 
        
        for (string s : ops) {
            if (s == "C") {
                int pt = pts.top(); 
                pts.pop();
                total -= pt; 
            } else if (s == "D") {
                int first = pts.top();
                pts.push(first+first); 
                total += first + first; 
            } else if (s == "+") {
                int first = pts.top();
                pts.pop();
                int second = pts.top();
                pts.pop(); 
                pts.push(second);
                pts.push(first);
                pts.push(first+second);
                total += first + second; 
            } else {
                int pt = stoi(s); 
                pts.push(pt);
                total += pt; 
            }
        }
        
        return total; 
    }
};