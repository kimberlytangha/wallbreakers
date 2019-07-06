class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int, int> childs;
        map<int, int> cookies; 
        
        for (int c : g) 
            childs[c]++;
        
        for (int sz : s) 
            cookies[sz]++;
        
        int contentChildren = 0; 
        
        for (auto sz = cookies.begin(); sz != cookies.end(); sz++) {
            for (auto c = childs.begin(); c != childs.end(); c++) {
                if (sz->first >= c->first) {
                    cout << sz->first << "     " << c->first << endl;
                    while (c->second > 0 && sz->second > 0) {
                        cout << sz->first << " " << sz->second << endl;
                        cout << c->first << " " << c->second << endl;
                        cout << endl;
                        c->second--; 
                        sz->second--; 
                        contentChildren++; 
                    }
                }
                
            }
        }
        
        return contentChildren; 
        
    }
};

// found in discussion + annotated 
class Solution {
public:
    int findContentChildren(vector<int>& monsters, vector<int>& cookies) {
        sort(monsters.begin(), monsters.end());
        sort(cookies.begin(), cookies.end());
        
        int child = 0; 
        int c = 0; 
        
        while ( child < monsters.size() && c < cookies.size()) {
            if (cookies[c] >= monsters[child]) {
                // if you know cookie size is big enough for child,
                // give cookie and immediately move to 
                // next child (greedy part)
                child++; 
            }
            
            // move cookie pointer always 
            c++; 
        }
        
        return child; 
    }
    
};