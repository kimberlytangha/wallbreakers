class Solution {
public:
    // time O(n^2)
    // space O(n) for set 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> common; 
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int k = 0; k < nums2.size(); k++) {
                if (nums1[i] == nums2[k]) {
                    // time O(logn) for set insertion 
                    common.insert(nums1[i]);
                    break; 
                }
            }
        }
        
        vector<int> res;
        for (auto item : common)
            res.push_back(item); 
        
        return res; 
    }
};

// Found in discussion 
class Solution {
public:
    
    // time O(n) bc loop through just one array
    // space O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s(nums1.begin(), nums1.end());
        vector<int> res; 
        
        for (int n : nums2) {
            // Cross check second array against set (nums1) to erase all instances if number appears
            if (s.erase(n))
                res.push_back(n); 
        }
        
        return res; 
    }
   
};