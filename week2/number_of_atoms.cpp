class Solution {
public:
    map<char, int> elements;
    stack<char> stk; 

    string countOfAtoms(string f) {
        int n = f.size(); 
        int i = 0; 
        
        bool update; 
        int mply;
        
        for (int i = 0; i < n; i++) {
            if (update) {
                mply = f[i] - '0'; 

                updateElements(mply); 

                stk.pop(); 
                update = false; 
                continue; 
            }

            if (isdigit(f[i]) || isalpha(f[i]) || f[i] == '(') {
                stk.push(f[i]);                       
            } else if (f[i] == ')') {
                update = true;
            }
        }

        updateElements(1); 

        string ans = ""; 
        for (auto k : elements) {
            ans += k.first;
            if (k.second > 1) {
                ans += to_string(k.second);  
            }
        }

        cout << ans << endl;
        return ans;  
    }


    void updateElements(int mply) {
        int n;
        char c; 
        bool hasDigit; 
        
        while (!stk.empty() && stk.top() != '(') {
            char item = stk.top(); 

            if (isdigit(item)) {
                hasDigit = true;
                n = item - '0'; 
                stk.pop();
                continue; 
            }

            if (hasDigit && isalpha(item)) {
                c = item; 

                if (elements.find(c) != elements.end()) {
                    elements[c] = (elements[c] + n) * mply; 
                } else {
                    elements[c] = n * mply; 
                }

                hasDigit = false; 
            } else if (isalpha(item)) {
                c = item;
                if (elements.find(c) != elements.end()) {
                    elements[c] = (elements[c] + 1) * mply; 
                } else {
                    elements[c] = 1 * mply; 
                }
                cout << item << " " << elements[c] << endl;
            }

            if (!stk.empty()) {
                stk.pop();
            }
        }

        return; 
    }

};