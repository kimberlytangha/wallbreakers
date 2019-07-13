class Solution {
public:
    // time O(n)
    // space O(1)
    bool detectCapitalUse(string s) {
        bool firstUpper = isupper(s[0]); 
        bool secondUpper = isupper(s[1]);
        
        for (int i = 1; i < s.length(); i++) {
            if (firstUpper) {
                if (secondUpper && islower(s[i]) || !secondUpper && isupper(s[i]))
                    return false;  
            } else if (isupper(s[i]))
                return false; 
        }

        return true; 
    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length(); 
        if (n == 1) 
            return true; 
        
        bool upperFirst = isupper(word[0]);
        bool upperSecond = isupper(word[1]);
        
        if (!upperFirst && upperSecond)
            return false; 
        
        for (int i = 2; i < n; i++) {
            if (upperFirst && upperSecond) {
                if (!isupper(word[i])) 
                    return false; 
            } else {
                if (isupper(word[i]))
                    return false; 
            }
        }
        
        return true; 
    }
};