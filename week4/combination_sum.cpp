class Solution {
public:
    // Ex.) [2,3,5,7]
    // 2
    // 22
    // 222
    // 2222     return 
    // 223      solution!
    // 23       
    // 233      return 
    // 26       return 
    // 3    
    // 33   
    // 333      return 
    // 36       return 
    // 6        
    // 66       return 
    // 7        solution!
    // 
    void findNumbers(vector<int>& c, int target, vector<vector<int>>& res, vector<int>& hold, int currIdx) { 
        // if current target dips below need to return 
        if (target < 0) 
            return; 

        // values in vector r add up to value we want
        if (target == 0) { 
            res.push_back(hold); 
            return; 
        } 

        // if target and new number a[i] dip below 0, 
        // you prune that part of the tree and index pointer forward
        // to check following elements  
        while (currIdx < c.size() && target - c[currIdx] >= 0) { 
            // vector to test in recursive call 
            hold.push_back(c[currIdx]); 
            
            // recursive call using updated hold vector 
            findNumbers(c, target - c[currIdx], res, hold, currIdx); 

            // if it doesn't work out, you remove c[i] element and continue with c[i+1]
            hold.pop_back(); 
            i++; 
        } 
    } 

    vector<vector<int> > combinationSum(vector<int>& candidates, int sum) { 
        vector<int> hold; 
        vector<vector<int>> res; 

        // sort input array 
        sort(candidates.begin(), candidates.end()); 
        
        // gets rid of all duplicates 
        auto uni = unique(candidates.begin(), candidates.end()); 
        candidates.erase(uni, candidates.end()); 
        
        findNumbers(candidates, sum, res, hold, 0); 

        return res; 
    } 
};