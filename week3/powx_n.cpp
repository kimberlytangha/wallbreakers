// fid 
class Solution {
public:
    // time O(??) - not sure  
    // space O(n) - we make n/2 calls to myPow()
    double myPow(double x, int n) {
        if (n==0) 
            // if the exponent is 0, return 1 bc math 
            return 1;
        
        // recursively divide exponent into halves until 0 reached
        // memoization occurs here
        double t = myPow(x,n/2);
        
        if (n % 2) {
            // n is odd, need to multiply the square of t by factor of base x           
            if (n < 0) {
                // if negative exponent
                return 1/x*t*t;
            } else {
                // if positive exponent
                return x*t*t;
            }
        } else {
            // n is even, just square t
            return t*t;
        }
    }
};