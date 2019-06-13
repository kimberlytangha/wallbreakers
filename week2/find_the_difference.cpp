class Solution {
public:
    // time O(n) to loop through the strings
    // space O(n) for freq vector 
    char findTheDifference(string s, string t) {
        vector<int> freq (26,0); 
        int n = s.size(); 
        for (int i = 0; i < n; i++) {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        
        freq[t[n] - 'a']--;
        
        char res;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == -1)
                res = char(i + 'a');
        }
        
        return res; 
    }
};

class Solution {
public:
    // time O(n)
    // space O(1) 
    char findTheDifference(string s, string t) {
        int n = s.size(); 
        int sSum = 0;
        int tSum = 0;
        
        // sum up all ascii values of chars
        for (int i = 0; i < n; i++) {
            sSum += s[i];
            tSum += t[i];
        }
        
        // add last char 
        tSum += t[n];
        
        // get char that id 
        return char(tSum - sSum);
    }
};