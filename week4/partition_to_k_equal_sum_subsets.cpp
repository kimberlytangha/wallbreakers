class Solution {
public:
    vector<int> n;
    int total; 
    int goalSum;
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // declare global vars
        n = nums; 
           
        int maxNum = 0;
        for (int num : nums) {
            total += num; 
            maxNum = max(maxNum, num);
        }
        
        // goalSum is the sum for each of the k partitions 
        goalSum = total / k;
        
        // maxNum > goal : optimizes bc nums only contains positives
        // so if there is a number greater than the goal sum for the 
        // partitions, we know we don't have a solution
        // total % k : check if total splits cleanly 
        if (maxNum > goalSum || total % k) 
            return false; 
        
        vector<bool> visited(n.size(), false);
        // partition entire array into k subsets
        return isSubset(k, 0, 0, visited);
    }
    
    bool isSubset(int k, int currSum, int start, vector<bool> visited) {
        // printf("%i %i : %i\n", currSum, goalSum, start); 
        
        if (k == 0)
            // split evenly so return true
            return true; 
        else if (currSum > goalSum)
            // impossible because can't split equal subsets 
            // so return false; 
            return false;
        else if (currSum == goalSum)
            // found a subset! not reduce k by 1 
            // and continue searching for subsets 
            return isSubset(k-1, 0, 0, visited);
        
        // currSum < goalSum so check what elements 
        // can be added to current subset
        for (int i = start; i < n.size(); i++) {
            if (!visited[i]) {
                visited[i] = true; 
                
                // check if i+1 can be part of subset??
                if (isSubset(k, currSum + n[i], i+1, visited )) 
                    return true; 
                
                // make n[i] an option for future partitions 
                visited[i] = false; 
            }
        }
        
        return false;
    }
};