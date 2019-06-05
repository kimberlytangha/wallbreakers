class Solution {
public:
    // time O(n) solution where n represents 
    // number of bits to represent highest binary 
    // that uses the same number of bits as num
    // space O(1)
    int findComplement(int num) {
        int cpy = num; 
        int numBits = 0; 
        
        // count how many bits num uses 
        while (cpy > 0) {
            numBits++; 
            cpy /= 2; 
        }
        
        // find highest binary that uses the same number of bits as num 
        int maxBin = pow(2, numBits) - 1; 
        
        // invert num's bits
        return num ^ maxBin;  
    }
};