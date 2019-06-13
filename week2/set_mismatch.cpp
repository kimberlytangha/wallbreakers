class Solution {
public:
    // O(nlogn)
    vector<int> findErrorNums(vector<int>& nums) {
        
        set<int> s; 
        int sz = nums.size(); 
        
        vector<int> ans (2, -1);
        
        // O(nlogn)
        for (auto n : nums) {
            if (s.find(n) != s.end())
                ans[0] = n; 
            else 
                // time for set insertion O(logn)
                s.insert(n);
        }
        
        // O(nlogn)
        for (int i = 1; i <= sz; i++) {
            if (s.find(i) == s.end()) {
                ans[1] = i; 
                break;
            }
        }
        
        return ans; 
    }
};

class Solution {
public:
    // time O(n) to create freq map 
    // space O(n)
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq (n, 0); 
        vector<int> ans (2,-1); 
        
        for (int num : nums) 
            freq[num-1]++;     
        
        for (int i = 0; i < n; i++) {
            if (ans[0] != -1 && ans[1] != -1) return ans;
            if (freq[i] == 0)
                ans[1] = i+1; 
            else if (freq[i] == 2)
                ans[0] = i+1;
        }
        
        return ans;
    }
};