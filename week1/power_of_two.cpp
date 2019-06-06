// Found in discussion 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        
        // we know that power of 2 means just 1 bit is 1
        // n-1 returns all other bits as 1
        // Example: 
        // n = 4    100
        // n-1 = 3  011
        // 100 & 011 => 000 (WORKS - valid power of 2)
        
        // Example: 
        // n = 5    101
        // n-1 = 4  100
        // 100 & 011 => 100 (invalid power of 2)
        return !( n & (n-1) ); 
    }
};