class Solution {
public:
    // time O(??) - not sure what the time is
    // space O(n) for the sums set 
    bool isHappy(int n) {
        
        if (n == 1) {
            return true;
        }
        
        string num = to_string(n); 
        
        set<int> sums; 
        
        int sum = 0; 
        while (sum != 1) {
            sum = 0; 
            
            for (int i = 0; i < num.length(); i++) {
                int digit = num[i] - '0';
                sum += digit * digit; 
            }
            
            cout << sum << endl;
            
            if (sums.find(sum) != sums.end()) 
                return false; 
            else 
                sums.insert(sum);
            
            num = to_string(sum); 
            
        }
        
        return true; 
    }
};