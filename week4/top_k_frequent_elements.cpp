// bucketize frequencies of each number and pick top k most frequent elements
class Solution {
public:
    // time O(n^2)
    // space O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res; 
        unordered_map<int,int> freq;
        vector<vector<int>> bucket (nums.size()+1, vector<int>{}); 
        
        // get word counter stored in hashmap
        for (int num : nums) 
            freq[num]++;     
        
        // loop through hm and bucketize the frequencies
        for (auto item: freq) {
            // int num = item.first; 
            // int count = item.second;
            bucket[item.second].push_back(item.first);
        }
        
        // loop through buckets and find your most frequent elements
        for (int i = bucket.size()-1; i >= 0; i--) {
            while (res.size() < k && !bucket[i].empty()) {
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
            }
            
            if (res.size() == k) {
                break;
            }
        }
        
        
        return res; 
    }
};

// faster solution using priority queues 
class Solution {
public:
    // time O(nlogn)
    // space O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> res;
        
        for(int num : nums)
            freq[num]++;

        // create max heap to order nums by frequency 
        // each pair is (num, count)
        priority_queue<pair<int,int>> pq; 
        
        // stores number of frequencies we expect to add to our res vector
        int topK = freq.size() - k; 
        
        // build pq to sort frequencies
        // time O(nlogn) to sort
        for (auto curr = freq.begin(); curr != freq.end(); curr++ ) {
            int num = curr->first; 
            int count = curr->second; 
            
            pq.push(make_pair(count, num));
            
            if (pq.size() > topK) {
                int mostFreq = pq.top().second;
                res.push_back(mostFreq);
                pq.pop(); 
            }
        }
        
        return res;
    }
};