// Spent 2 hours trying to debug with no luck
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res; 
        
        int slen = s.length(); 
        int plen = p.length(); 
        
        for (int i = 0; i <= slen - plen; i++) {
            multiset<char> ms(p.begin(), p.end());
            
            for (int k = i; k < i + plen; k++) {
                cout << s[k] << endl;
                if (ms.find(s[k]) == ms.end()) {
                    break;
                } else {
                    auto itr = ms.find(s[k]);
                    ms.erase(itr);
                }
                
                if (k == i + plen - 1) {
                    res.push_back(i);             
                }
                
            }
            
        }
        
        return res;
    }
};

// Solution found in discussion?
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0), ans;
        for (char c : p)
            ++m[c - 'a'];
        
        int i = 0, j = 0, counter = p.length(); 
        while (j < s.length()) {
            if (m[s[j++] - 'a']-- > 0)
                --counter;
            
            if (!counter)
                ans.push_back(i);
            
            if (j - i == p.length() && m[s[i++] - 'a']++ >= 0)
                ++counter;
        }
        return ans;
    }
};