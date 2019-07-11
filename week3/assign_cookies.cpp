// fid
class Solution {
public:
    // time O(nlogn) for sorting vectors 
    // space O(1) 
    int findContentChildren(vector<int>& monsters, vector<int>& cookies) {
        sort(monsters.begin(), monsters.end());
        sort(cookies.begin(), cookies.end());
        
        int child = 0; 
        int c = 0; 
        
        while ( child < monsters.size() && c < cookies.size()) {
            if (cookies[c] >= monsters[child]) {
                // if you know cookie size is big enough for child,
                // give cookie and immediately move to 
                // next child (greedy part)
                child++; 
            }
            
            // move cookie pointer always 
            c++; 
        }
        
        return child; 
    }
    
};