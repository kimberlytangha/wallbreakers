class Solution {
public:
    set<char> vowels = {'a','e','i','o','u'};
    
    // time O(nlogn) to search through entire string and search set?
    // space O(1) 
    string reverseVowels(string s) {
        int i = 0; 
        int j = s.size() - 1; 
        
        while (i < j) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i++], s[j--]);
            } else {
                if (!isVowel(s[i])) 
                    i++; 

                if (!isVowel(s[j])) 
                    j--;  
            }
        }
        
        return s; 
    }
    
    bool isVowel(char c) {
        c = tolower(c); 
        return vowels.find(c) != vowels.end();
    }
};

class Solution {
public:
    set<char> v = {'a', 'e', 'i', 'o', 'u'};
    
    string reverseVowels(string s) {
        int len = s.length(); 
        for (int i = 0, j = len - 1; i < j; ) {
            if (isvowel(s[i]) && isvowel(s[j])) {
                swap(s[i++], s[j--]); 
            } else {
                if (!isvowel(s[i])) 
                    i++; 
                
                if (!isvowel(s[j]))
                    j--; 
            }
        }
        
        return s; 
    }
    
    bool isvowel(char c) {
        c = tolower(c); 
        return v.find(c) != v.end(); 
    }
};
