class Solution {
public:
    // time O(n) 
    // space O(n) for hash map storage 
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> pmap;
        unordered_map<string, char> smap;
        
        int i = 0; 
        int pIdx = 0; 
        int sLen = str.length();
            
        // time O(n) for looping through all char in string
        for (int j = 0; j < sLen; j++ ) {
            if (str[j+1] == ' ' || j == sLen - 1) {
                
                string word = str.substr(i, j-i+1); 
                char c = pattern[pIdx];
                pIdx++;
                
                cout << word << " " << c << endl;
                
                // time O(1) 
                if (pmap.find(c) == pmap.end()) {
                    pmap[c] = word;    
                } else {
                    if (pmap[c] != word)
                        return false; 
                }
                
                // time O(1) 
                if (smap.find(word) == smap.end()) {
                    smap[word] = c;
                } else {
                    if (smap[word] != c)
                        return false; 
                }
                
                i = j + 2; 
                j += 1;
            }
        }

        return pIdx == pattern.length(); 
    }
};