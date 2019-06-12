class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        
        // create unique set of all jewel types
        unordered_set<char> jewels(J.begin(), J.end());
        
        for (char c : S) {
        	// look for matching stone in jewel set
        	// O(logn)
            if (jewels.find(c) != jewels.end()) 
                res++;
        }
		
        return res; 
    }
};