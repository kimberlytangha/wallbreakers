// found in discussion
class Solution {
public:
    
    // time O(n)
    // space O(1)
    int titleToNumber(string s) {
        int col = 0; 
        int size = s.length();
        for (int i = 0; i < size; i++) {
            col = col * 26 + (s[i] - 'A' + 1);
        }
        return col;
    }
};