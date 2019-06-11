// found in discussions
class Solution {
public:
    // time O(n) for size of A string array 
    // space O(n) for storing resulting anagram 
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s; 
        
        for (auto word : A) {
            string even, odd; 
            
            for (int k = 0; k < word.size(); k++) {
                if (k % 2) 
                    odd += word[k]; 
                else
                    even += word[k]; 
            }
            // sort bc we want chars to be ordered in even and odd string
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            s.insert(even + odd); 
        }
        
        return s.size(); 
    }
};