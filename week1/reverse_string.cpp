class Solution {
public:
    // time less than O(n) bc go through all char in list
    // space O(1) bc no extra memory used 
    void reverseString(vector<char>& s) {
        int i = 0; 
        int j = s.size() - 1;
        
        while (i < j) {
            char tmp = s[i];
            s[i++] = s[j]; 
            s[j--] = tmp; 
        }
    }
};

class Solution {
public:
    // time O(n)
    // space O(1)
    void reverseString(vector<char>& s) {
        int n = s.size(); 
        int l = 0; 
        int r = n - 1; 
        
        while (l < r)
            swap(s[l++],s[r--]);
    }
};