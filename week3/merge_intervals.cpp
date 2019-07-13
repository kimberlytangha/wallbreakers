// solution is very similar to the 
// min number of arrows to pop balloons
class Solution {
public:
    // time O(nlogn) for sorting
    // space O(n) to store solution
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) 
            return intervals;
        
        vector<vector<int>> res; 
        // sort using first element
        sort(intervals.begin(), intervals.end(), mySort);
        
        int n = intervals.size();
        int i = 0; 
        while (i < n) {
            int left = intervals[i][0];
            int right = intervals[i][1]; 
            
            i++; 
            // check right against all subsequent lefts
            while (i < n && intervals[i][0] <= right) {
                // interval overlaps so extend range of right
                // don't need to update left 
                right = max(intervals[i][1], right);
                i++; 
            }
            
            res.push_back({left, right});
        }
        
        return res; 
    }
    
    static bool mySort(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
};