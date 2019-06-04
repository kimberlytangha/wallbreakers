class Solution {
public:
//     int singleNumber(vector<int>& nums) {
//         // holds remaining bits after xor operation
//         int left = nums[0]; 
        
//         for (int i = 1; i < nums.size(); i++) {
//             left ^= nums[i];
//         }
        
//         return left; 
//     }
    
    // time O(n) bc only bitwise operator XOR used
    // space O(1) no extra space used
    int singleNumber(vector<int>& nums) {
        // holds remaining bits after xor operation
        int left = 0; 
	
        for (auto n : nums) {
            left ^= n;
        }
        
        return left; 
    }
};