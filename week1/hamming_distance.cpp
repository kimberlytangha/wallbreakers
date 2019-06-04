class Solution {
public:
    // time O(n) where n represents number of bits in max(x,y)
    // space O(1) 
    int hammingDistance(int x, int y) {
        if (x == y) {
            return 0; 
        }
        
        int count = 0;
        
        while (x > 0 || y > 0) {
            if ((x&1) ^ (y&1)) {
                count++;
            }
            x = x >> 1;
            y = y >> 1;
        }
        
        return count; 
    }
};
