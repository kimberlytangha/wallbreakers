/////////////////////////
// Dynamic Programming //
/////////////////////////

// Define recurrence relation 
// When word1[i] != word2[i]
// 1. Replace word1[i] = word2[i]
// 2. Delete word1[i-1]
// 3. Insert word2[j+1]
class Solution {
public:
    int minDistance(string word1, string word2) {
        int startLen = word1.size(), endLen = word2.size();
        
        vector<vector<int> > dp(startLen + 1, 
            vector<int>(endLen + 1, 0));
        
        // initalize deletes
        for (int i = 1; i <= startLen; i++) 
            dp[i][0] = i;
        
        // initalize insert
        for (int j = 1; j <= endLen; j++) 
            dp[0][j] = j;

        // i loops through start (word1)
        // j loops through final (word2)
        for (int i = 1; i <= startLen; i++) {
            for (int j = 1; j <= endLen; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // replace word2[j-1] with word1[i-1]    
                    // dp[i - 1][j - 1] + 1
                    int min1 = dp[i - 1][j - 1];
                    cout << min1 << endl;

                    // inserting word2[j-1] :   dp[i][j-1] + 1 
                    // delete word1[i-1]    :   dp[i - 1][j] + 1
                    int min2 = min(dp[i][j - 1], dp[i - 1][j]); 
                    dp[i][j] = min(min1, min2) + 1;
                }
                
                // printdp(dp); 
            }
        }

        // return the minimum number of operations 
        return dp[startLen][endLen];
    }
    
    void printdp(vector<vector<int> > &dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) 
                cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

// More efficient using 2 vectors to store the min 
// num of operations
// Can also reduce to just using 1 vector
class Solution {
public:
    int minDistance(string word1, string word2) {
        int startLen = word1.size(), endLen = word2.size();
        vector<int> pre(endLen + 1, 0);
        vector<int> cur(endLen + 1, 0);
        
        // for delete
        for (int k = 1; k <= endLen; k++) 
            pre[k] = k;
        
        for (int i = 1; i <= startLen; i++) {
            cur[0] = i;

            for (int k = 1; k <= endLen; k++) {
                if (word1[i - 1] == word2[k - 1]) {
                    cur[k] = pre[j - 1];
                } else {
                    // replacing
                    int min1 = pre[k - 1]; 

                    // insert : cur[k-1]
                    // delete : pre[k]
                    int min2 = min(cur[k - 1], pre[k]);
                    cur[k] = min(min1, min2) + 1;
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return pre[endLen];
    }
};