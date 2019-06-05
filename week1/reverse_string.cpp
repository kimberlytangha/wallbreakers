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

// Found solution in discussion 
class Solution {
public:
    // time less than O(n) bc go through all char in list
    // space O(1) bc no extra memory used 
    void reverseString(vector<char>& s) {
        int i = 0; 
        int j = s.size() - 1;
        
        while (i < j) 
            // use swap method to reduce LOC
            swap(s[i++], s[j--]);
    }
};