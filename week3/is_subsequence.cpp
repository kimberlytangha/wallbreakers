class Solution {
public:
    // time O(m) where m is the longer string length of t 
    // space O(1) 
    bool isSubsequence(string s, string t) {
        int p = 0; 
        int q = 0; 
        
        // just use 2 while loops as opposed to one for and while loop
        // and use 2 pointers to keep track of where you are in
        // s and t
        while (p < s.length() && q < t.length()) {
            if (s[p] == t[q]) {
                p++;
                q++;
            } else {
                q++; 
            }
        }
        
        return (p == s.length());
    }
};