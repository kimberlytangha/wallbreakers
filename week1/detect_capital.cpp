class Solution {
public:
    // time O(n)
    // space O(1)
    bool detectCapitalUse(string s) {
        bool firstUpper = isupper(s[0]) ? 1 : 0; 
        bool secondUpper = isupper(s[1]) ? 1 : 0; 
        
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