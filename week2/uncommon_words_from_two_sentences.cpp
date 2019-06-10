class Solution {
public:
    
    unordered_map<string, int> freq;
    
    // time O(n) bc helper function has O(n) time 
    // space O(n) for hash map word + frequency storage 
    vector<string> uncommonFromSentences(string A, string B) { 
        extractWords(A); 
        extractWords(B); 
        
        vector<string> res;

        // time O(w) for number of words in hash map  
        for (auto item : freq) {
            if (item.second == 1) 
                res.push_back(item.first); 
        }
        
        return res; 
    }
    
    // time O(n) for number of characters in the string s
    void extractWords(string s) {
        int i = 0; 
        
        for (int j = 0; j < s.length(); j++) {
            if (s[j+1] == ' ' || j == s.length()-1) {
                // time O(1) insert into HM
                freq[s.substr(i, j-i+1)]++; 
                i = j + 2; 
                j += 1; 
            }
        }
    }
};


