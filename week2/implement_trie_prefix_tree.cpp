// found in discussion
class TrieNode {
public:
    TrieNode *children[26];
    bool leaf;

    TrieNode() {
        leaf = false; 
        
        // void fill_n (OutputIterator first, Size n, const T& val);
        // assigns val to the first N elements of the array ref first
        fill_n(children, 26, nullptr);
    }

};

class Trie {
public:
    Trie() {
        root = new TrieNode(); 
        root->leaf = false;   
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *curr = root; 
        int slen = s.size(); 
        int i = 0; 

        if (slen > 0) {
            // traverse to see if parts of s exist already in tree
            while (s[i] && curr->children[s[i] - 'a']) {
                curr = curr->children[s[i] - 'a'];
                i++; 
            }

            if (!s[i]) {
                // needs to mark as leaf 
                curr->leaf = true; 
            } else {
                while (s[i]) {
                    curr->children[s[i] -'a'] = new TrieNode();
                    curr = curr->children[s[i] -'a'];  
                    i++;
                }
                // assign last letter as leaf 
                curr->leaf = true; 
            }
        }

    }

    // Returns if the word is in the trie.
    bool search(string s) {
        TrieNode *curr = root; 
        int slen = s.size(); 
        int i = 0; 

        if (slen > 0) {
            // traverse to see if parts of s exist already in tree
            while (s[i] && curr->children[s[i] - 'a']) {
                curr = curr->children[s[i] - 'a'];
                i++; 
            }

            if (!s[i] && curr->leaf)
                // no more char in s to check and we are at leaf 
                return true; 
        }
        return false; 
    }

    bool startsWith(string s) {
        TrieNode *curr = root; 
        int slen = s.size(); 
        int i = 0; 

        if (slen > 0) {
            // traverse to see if parts of s exist already in tree
            while (s[i] && curr->children[s[i] - 'a']) {
                curr = curr->children[s[i] - 'a'];
                i++; 
            }

            if (s[i])
                // if there are still chars in s that are not in the tree
                return false; 
        }
        return true; 
    }

private: 
    TrieNode *root; 
};
