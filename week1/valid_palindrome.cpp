class Solution {
public:
    // time O(n) because traverse through string once
    // space O(1) no extra space used
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1; 
        
        while (i < j) {
            char ci = tolower(s[i]);
            char cj = tolower(s[j]); 
            
            if (isValidChar(ci) && isValidChar(cj)) {
                if (ci != cj) 
                    return false;
                
                i++;
                j--; 
            }
            
            if (!isValidChar(ci)) 
                i++; 
            
            if (!isValidChar(cj)) 
                j--;
        }
        
        return true; 
    }
    
    bool isValidChar(char c) {
        return isalnum(c) && c != ' '; 
    }
};