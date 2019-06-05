// first solution 
class Solution {
public:
    // time O(n) for number of integers to check from 1...n
    // space O(n) to hold n numbers and related string
    vector<string> fizzBuzz(int n) {
        vector<string> res; 
    
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) 
                res.push_back("FizzBuzz");
            else if (i % 5 == 0) 
                res.push_back("Buzz");
            else if (i % 3 == 0)
                res.push_back("Fizz");
            else
                res.push_back(to_string(i));
        }
        
        return res; 
    }
};

// more optimal solution
class Solution {
public:
    // time O(n) for number of integers to check from 1...n
    // space O(n) to hold n numbers and related string
    vector<string> fizzBuzz(int n) {
        vector<string> res; 
  
        for (int i = 1; i <= n; i++) {
            string s = "";
            if (i % 3 == 0) 
                s = "Fizz";
            if (i % 5 == 0) 
                s += "Buzz";

            if (s.empty()) {
                res.push_back(to_string(i)); 
            } else {
                res.push_back(s);     
            }
        }
        
        return res; 
    }
};