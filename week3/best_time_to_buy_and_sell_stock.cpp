/////////////////////////
// Iterative Solution  //
/////////////////////////

class Solution {
public:
    // time O(n^2) set buy-sell for every possible pair 
    // space O(1) constant 
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) 
            return 0;
        
        int maxP = 0; 
        
        for (int b = 0; b < prices.size() - 1; b++) 
            for (int s = b+1; s < prices.size(); s++)
                maxP = max( prices[s] - prices[b], maxP );
        
        return maxP; 
    }
};

////////////////////////
// Recursive Solution //
////////////////////////

// splices array in this order: [0,1] [0,2], [0,3], [0,4]...[0,n]
// with selling day on end => [begin, end]
// reassign maxProfit continually 
// 
// time O(??) - not sure!
// space O(n)
class Solution {
public:
    vector<int> p;
    
    int maxProfit(vector<int>& prices) {
        p = prices; 
        return spliceArr(prices.size());
    }
    
    // spliceArr prices vector into subarray
    int spliceArr(int sz) {
        if (sz == 0) 
            // don't want array to be empty 
            return 0; 
        else {
            int maxProfit = spliceArr(sz - 1);
            for (int i = 0; i < sz; i++) 
                // check last element against every other element 
                // p[sz-1] => last 
                // reassign maxProfit to highest value 
                maxProfit = max(maxProfit, p[sz-1] - p[i]);
            return maxProfit;
        }
        
    }
};

//////////////////////////////////
// Dynamic Programming Solution //
//////////////////////////////////

class Solution {
public:
    // time O(n) for looping once 
    // space O(n) for cache 
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) 
            return 0;
        
        // memoization
        vector<int> maxPrices (prices.size(), 0);
        
        int minBuy = INT_MAX; 
        
        for (int i = 0; i < prices.size(); i++) {
            // finds minimum buying price and stores it
            minBuy = min(minBuy, prices[i]);
            
            if (i == 0)
                // prevent out of bounds issue in next assign case
                continue;
            
            // retrieves max profit so far
            int maxSoFar = maxPrices[i-1];
            // computes profit for minBuy and sell price
            int localProfit = prices[i] - minBuy; 
            
            // stores max profit between two above
            maxPrices[i] = max(localProfit, maxSoFar);
        }
        
        // returns max profit 
        return maxPrices.back();
    }
};