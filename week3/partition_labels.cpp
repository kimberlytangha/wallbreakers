// discussion
class Solution {
public:
    // time O(n*m) where n is the length of string 
    // and m is length of maxium partition
    // space O(n) to store last occurences 
    vector<int> partitionLabels(string S) {
        vector<int> last(26, -1);
        
        // store last occurence of each char 
        for (int i = 0; i < S.length(); i++) 
            last[S[i] - 'a'] = i; 
        
        vector<int> res; 
        
        // i holds the index of the beginning of recent partition 
        // j is the moving pointer that loops the string
        // lastOccurrence is the index of current partition's furthest occurence 
        for (int j = 0, i = j; j < S.length(); i = j) {
            for (int lastOccurence = j; j <= lastOccurence; j++) {
                // in this loop we, check all values from the 
                // original j to the lastOccurence, which may be 
                // updated if chars in between occur beyond a 
                // previous lastOccurence 
                lastOccurence = max(lastOccurence, last[S[j] - 'a']);
            }
            
            // find the length of this partition 
            res.push_back(j-i);
        }
        
        return res; 
    }
};