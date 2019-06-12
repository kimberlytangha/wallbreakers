class Solution {
public:
    // time O(n) for string cleaning  
    // space O(n) for frequency 
    string mostCommonWord(string pg, vector<string>& banned) {
        // O(logn) to create ordered set? 
        set<string> bd(banned.begin(), banned.end());
        unordered_map<string, int> freq; 
        
        for (auto & c : pg) 
            c = isalpha(c) ? tolower(c) : ' ';
        
        istringstream iss(pg);
        string word; 
        pair<string, int> ans = {"", 0};
        
        while (iss >> word) {
            if (bd.find(word) == bd.end()) {
                freq[word]++;    

                if (freq[word] > ans.second) 
                    ans = make_pair(word, freq[word]);
            }
        }
        
        return ans.first;
    }
};

// found in discussions
class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        // use set bc have unique series of words
        unordered_set<string> bd(banned.begin(), banned.end()); 
        
        // use HM for storing unique keys : frequencies 
        unordered_map<string, int> freq; 
        
        for (auto & c : p) 
            c = isalpha(c) ? tolower(c) : ' ';
        
        istringstream iss(p);
        string wrd;
        
        pair<string, int> ans = {"", 0};
        
        // while string exists in stream
        while (iss >> wrd) {
            freq[wrd]++; 
            
            if (bd.find(wrd) == bd.end() && freq[wrd] > ans.second)
                ans = make_pair(wrd, freq[wrd]);
        }
                
        return ans.first; 
    }
};