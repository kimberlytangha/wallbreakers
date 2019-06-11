// found in discussions 
class Solution {
public:
    // time O(m) to copy candies into set
    // space O(n) to store n unique elements 
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s(candies.begin(), candies.end()); 
        return min(s.size(), candies.size()/2); 
    }
};