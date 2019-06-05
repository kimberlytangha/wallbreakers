class Solution {
public:
    // time O(n) to loop through each char in string s and t
    // space O(n) to store unique char in s and their frequencies in hashmap
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }   
        
        unordered_map<char, int> mp; 
        
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
            } else {
                mp[s[i]] = 1; 
            }
        }
        
        for (int i = 0; i < t.length(); i++) {
            if (mp.find(t[i]) != mp.end()) {
                if (mp[t[i]] == 1) {
                    mp.erase(t[i]);
                } else {
                    mp[t[i]]--;                     
                }
            } else {
                return false; 
            }
        }
        
        return mp.empty(); 
    }
};

// found optimal solution in discussions 
class Solution {
public:
    // time O(n) but faster bc array usage
    // space O(n) 
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false; 
        }
        
        // faster to use primitive array 
        int freq[26] = {0}; 
        
        // increment or decrement freq array
        // after looping through s and t, eách char freq 
        // should be net 0 
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++; 
            freq[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                return false; 
            }
        }
        
        return true; 
    }
};
