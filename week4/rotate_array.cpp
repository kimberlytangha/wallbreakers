class Solution {
public:
    // Idea is to store rotated part in queue
    // then delete rotated part from array 
    // and re-add queue items to beginning of array 
    
    // time O(n^2) for adding from queue to beginning of array 
    // space O(n) for queue
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        int numMoves = k % n;
        
        if (!numMoves) 
            return; 
        
        queue<int> tmp; 
        for (int i = n - 1; i >= n - numMoves; i--) {
            tmp.push(nums[i]);
            nums.pop_back(); 
        }
            
        while (!tmp.empty()) {
            // O(n)
            nums.insert(nums.begin(), tmp.front());            
            tmp.pop();
        }
    }
};

class Solution {
public:
    // Idea is to cpy over in pieces 
    // Store the rotated part in cpy array
    // then cpy over rest of nums
    
    // time O(n)
    // space O(n)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        int numMoves = k % n;
        
        // returns bc array will be same
        if (!numMoves) 
            return; 
        
        vector<int> cpy (nums.size(), 0); 
        int cpyIdx = 0; 
        for (int i = n - numMoves; i < n; i++) {
            // copy over rotated part of array 
            cpy[cpyIdx] = nums[i]; 
            cpyIdx++; 
        }
        
        for (int i = 0; i < n - numMoves; i++) {
            // cpy over remaining part of nums into cpy
            cpy[cpyIdx] = nums[i]; 
            cpyIdx++; 
        }
        
        nums = cpy; 
    }
};

class Solution {
public:
    // Idea is to cpy over array in one loop 
    
    // time O(n)
    // space O(n)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        int numMoves = k % n;
        
        // returns bc array will be same
        if (!numMoves) 
            return; 
        
        vector<int> cpy (nums.size(), 0); 
        for (int i = 0; i < n; i++) {
            int newIdx = (i + k) % n;
            cpy[newIdx] = nums[i];
        }
        
        nums = cpy; 
    }
};