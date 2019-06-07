class Solution {
public:
    string orig; 

    // time O(n) i think for looping through string 
    // and half of each word
    // space O(1) i think for string
    string reverseWords(string s) {
        orig = s; 
        
        for (int i = 0, j = 0; j < s.size() && i < s.size(); j++) {
            if (j == s.size() - 1 || s[j + 1] == ' ') {
                reverse(i, j); 
                j++; 
                i = j + 1;
            }
        }
        
        return orig; 
    }
    
    void reverse(int i , int j) {
        while (i < j) {
            swap(orig[i++], orig[j--]); 
        }
    }
};