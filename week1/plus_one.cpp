// Found solution in discussion
class Solution {
public:
    // time O(n) 
    // space O(1) 
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size(); 
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++; 
                return digits; 
            }
        }
        
        digits[0] = 1; 
        digits.push_back(0); 
        return digits; 
    }
};