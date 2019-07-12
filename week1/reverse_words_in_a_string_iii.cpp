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

// String parsing using istringstream 
class Solution {
public:
    // time O(??)
    string reverseWords(string s) {
        if (s.empty())
            return s;
        
        // initalize with s
        istringstream iss(s);
        string res;
        
        // loop through stream 
        for (string word; iss >> word; ) {
            int l = 0; 
            int r = word.length() - 1; 
            
            // reverse each word 
            while (l <= r)
                swap(word[l++],word[r--]);
                
            res += word + " "; 
        }
        
        // remove space at end
        // res.erase(res.end()); 
        res.erase(res.length()-1, 1);
        
        return res;
    }
};