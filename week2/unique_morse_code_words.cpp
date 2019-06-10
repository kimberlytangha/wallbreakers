class Solution {
public:
    // time O(n*m) for n words and m max length of word
    // space O(n) for morse code vector 
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        
        vector<string> morse = {
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",
            ".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--",
            "--.."
        };
        
        set<string> unique; 
        
        int size = words.size(); 
        
        for (int k = 0; k < size; k++) {
            string s = "";
            
            for (int i = 0; i < words[k].length(); i++) {
                int idx = words[k][i] - 'a';
                s += morse[idx];
            }
            
            // time O(logn) to find and insert into set
            if (unique.find(s) == unique.end()) {
                unique.insert(s);
            }
        }
        
        return unique.size(); 
    }
};

class Solution {
public:
    // time O(n*m) for n words and m max length of word
    // space O(n) for morse code vector 
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        
        // Space O(n)
        vector<string> morse = {
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",
            ".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--",
            "--.."
        };
        
        // use over ordered set so that you have O(1) insert 
        unordered_set<string> unique; 
        
        int size = words.size(); 
        
        for (int k = 0; k < size; k++) {
            string s = "";
            
            for (int i = 0; i < words[k].length(); i++) {
                // O(1) look up
                s += morse[words[k][i] - 'a'];
            }
            
            // time O(1) to find and insert into unordered set
            if (unique.find(s) == unique.end()) {
                unique.insert(s);
            }
        }
        
        return unique.size(); 
    }
};