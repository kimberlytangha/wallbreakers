// iterative solution 
class Solution {
public:
    // time O(n^2) set buy-sell for every possible pair 
    // space O(1) constant 
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int maxProfit = 0; 
        
        for (int buy = 0; buy < prices.size() - 1; buy++) {
            for (int sell = buy+1; sell < prices.size(); sell++) {
                // not sure if this counts at memoization?
                maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            }
        }
        
        return maxProfit; 
    }
};


// recursive solution
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