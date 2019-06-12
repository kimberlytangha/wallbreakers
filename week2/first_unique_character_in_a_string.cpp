class Solution {
public:
    // time O(n) for creating freq hm 
    // space O(n) for hm
    int firstUniqChar(string s) {
        
        unordered_map<int, int> freq; 
        for (auto k : s) 
            freq[k - 'a']++; 
        
        int len =  s.length(); 
        for (int i = 0; i < len; i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }
        
        return -1; 
    }
};