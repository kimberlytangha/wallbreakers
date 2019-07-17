class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(); 
        vector<int> res (len1, -1);
        
        stack<int> cpy; 
        stack<int> hold; 
        
        for (int val : nums2) 
            cpy.push(val); 
        
        for (int i = 0; i < len1; i++) {
            int nextGreater = -1; 
            int curr = nums1[i];
            
            // we know every element is unique in nums2
            // so we jump out of while when we find the same
            // element 
            while (curr != cpy.top()) {
                int topVal = cpy.top();
                if (topVal > curr)
                    nextGreater = topVal; 
                
                // pop cpy into hold 
                hold.push(topVal);
                cpy.pop(); 
            }
            
            if (nextGreater != -1) 
                res[i] = nextGreater; 
            
            while (!hold.empty()) {
                cpy.push(hold.top());
                hold.pop(); 
            }
        }
        
        return res; 
    }
};