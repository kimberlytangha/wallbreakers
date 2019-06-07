class Solution {
public:
    // time O(m*n) where m is length of first word
    // n is number of other words in list 
    // space O(1) 
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        
        if (!len)
            return ""; 
        
        string prefix = "";
        bool stop = false;
        
        // loop through each char in first word
        for (int i = 0; i < strs[0].length(); i++) {
            char target = strs[0][i];   
            
            for (int j = 1; j < len; j++) {
                if (strs[j][i] != target) {
                    stop = true; 
                    break;
                }
            }
            
            if (stop)
                break;
            else {
                cout << target << endl;
                prefix += target; 
            }
        }
        
        return prefix; 
    }
};