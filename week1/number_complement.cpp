class Solution {
public:
    // time O(n) solution where n represents 
    // number of bits to represent highest binary 
    // that uses the same number of bits as num
    // space O(1)
    int findComplement(int num) {
        int cpy = num; 
        int numBits = 0; 
        
        while (cpy > 0) {
            numBits++;
            // want to see how many bits there are so divide by 2
            // Ex.) 8 4 2 1
            // .    0 1 0 0     num = 5
            cpy /= 2; 
        }
        
        // 0 1 0 0     num = 5
        // 0 1 1 1     ones = 7 
        int ones = pow(2, numBits) - 1; 
        return num ^ pow(2, numBits) - 1; 
    }
};