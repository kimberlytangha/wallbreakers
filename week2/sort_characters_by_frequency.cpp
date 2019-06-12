// couldn't come up with right ds to use 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq; 
        for (auto k : s) {
            freq[k]++;
        }
        
        unordered_set<char> sortedFreq; 
        for (auto k : freq) {
            cout << "adding flipped <int, char>" << endl; 
            cout << k.second << " " << k.first << endl;
            sortedFreq.insert();
        }
        
        cout << "SORTED freq below" << endl;
        for (auto k : sortedFreq) {
            cout << k.first << " " << k.second << endl;
        }
        
        // for (auto k : freq) {
        //     cout << k.first << " " << k.second << endl;
        // }
        
        string res; 
        for (auto k : sortedFreq) {
            int count = 0;
            while (count < k.first) {
                res += k.second;
                count++; 
            }
        }
        
        // cout << "here" << endl;
        // for (auto k : sortedFreq) {
        //     cout << k.first << " " << k.second << endl;
        // }
        
        return res;
    }
};

// found in discussion
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size(); 
        unordered_map<char,int> freq;
        
        // plus 1 to avoid complex indexing 
        // string at index k in bucket will be the concatenated
        // chars that appeared k times in string 
        vector<string> bucket ( n+1 , "" );
        
        string ans;

        // count frequency of each character
        for (auto c : s) 
            freq[c]++;
        
        // pool together characters with common frequencies  
        for (auto f : freq) {
            int count = f.second;
            char character = f.first;

            // bucket[2] might look like "aappyyww"
            bucket[count].append(count, character);
        }
        
        // we know the max freq will be n
        // so we start from most freq at n 
        // and work downward in our bucket
        for (int i = n; i > 0; i--) {
            if (!bucket[i].empty())
                cout << bucket[i] << endl;
                ans.append(bucket[i]);
        }
        
        return ans;
    }
};