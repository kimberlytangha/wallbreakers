class Solution {
public:
    // time O(logn) where n represents number of digits of bits in N
    // space O(1) bc no additional space used 
    int binaryGap(int N) {
        int last = -1; 
        int maxDist = 0; 
        
        // bitshift N to right and check for 1 in binary rep
        // reassign maxDist as needed when 1 pairs are found
        for (int i = 0; i < 32; i++) {
            if (((N >> i) & 1) > 0) {
                if (last >= 0) {
                    maxDist = max(maxDist, i - last);
                }
                last = i; 
            }
        }
        
        return maxDist; 
    }
};

// solution found in discussion 
class Solution {
public:
    // time O(n) where n represents num bits in N 
    // space O(1) bc no additional space needed
    int binaryGap(int N) {
        int ans = 0;
        
        // integer has 32 bit binary (max)
        // Here it set d = -32 in order to consider the situation 
        // when there is no 1 in binary.
        for (int dist = -32; N > 0; N /= 2, dist++) {
            if (N % 2) {
                // if there is a rem, you know there is a 1 at that location
                ans = max(ans, dist);
                dist = 0;
            }
        }
        
        // 22 => 01101 (reverse order when finding bit rep using % 2)
        
        return res; 
    }
};