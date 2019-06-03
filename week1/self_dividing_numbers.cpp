class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> sdn; 
        
        // time O(n * k) where n is length between right - left
        // k is the number of digits in right 
        // space O(n) where n is length of answers vector
        for (int i = left; i <= right; i++) {
            string number = to_string(i);
            bool isSDN = true; 
            
            // loop through all digits in number i and check divisibility
            for (int k = 0; k < number.length(); k++) {
                int div = number[k] - '0';
                if (div == 0 || i % div) {
                    isSDN = false;                        
                    break;
                }
            }
            
            if (isSDN) {
                sdn.push_back(i); 
            }
         }
        
        return sdn;
    }
};

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> sdn; 
        
        // time O(n) where n is length between right - left
        // space O(n) where n is length answers vector
        for (int i = left; i <= right; i++) {
            if (isSDN(i)) {
                sdn.push_back(i); 
            }
         }
        
        return sdn;
    }
    
    bool isSDN(int i) {
        // num /= 10 removes one's place for each iteration 
        // Ex.) 537 => 53 => 3
        for (int num = i; num > 0; num /= 10) {
            // (num % 10) checks if number contains zero
            // second condition checks if orig number is divisible by each digit 
            // get one's place digit using num % 10
            if ( !(num % 10) || (i % (num % 10)) ) {
                return false;
            }
        }
        return true; 
    }
};