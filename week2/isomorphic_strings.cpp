class Solution {
public:
    // time O(n) 
    // space O(n) for number of unique KVP 
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) 
            return false;
        
        unordered_map<char, char> st;
        unordered_map<char, char> ts;
        
        int len = s.length(); 
        
        for (int i = 0; i < len; i++) {
            // make sure char s[i] and t[i] have the 
            // expected partner in their st/ts hashmaps 
            if (st.find(s[i]) != st.end() && st[s[i]] != t[i] || ts.find(t[i]) != ts.end() && ts[t[i]] != s[i]) 
                return false; 
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        
        return true; 
    }
};

// optimal solution in discussions 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> st(256, -1); 
        vector<int> ts(256, -1); 
        
        int n = s.size(); 
        
        // we know char at s[i] and t[i] both appear at location I 
        // string not isomorphic if the indicies stored at 
        // st[s[i]] and ts[t[i]]s are not equal 
        for (int i = 0; i< n; i++) {
            if (st[s[i]] != ts[t[i]])
                return false;
            
            st[s[i]] = i + 1; 
            ts[t[i]] = i + 1; 
        }
        
        return true; 
    }
};