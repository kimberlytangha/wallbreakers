class MyQueue {
public:
    stack<int> q;
    stack<int> hold;
    int size; 
    
    MyQueue() {}
    
    // time O(1)
    void push(int x) {
        q.push(x);
        size++;
    }
    
    // time O(n)
    int pop() {
        if (q.empty() && hold.empty()) {
            return -1;
        }
        
        if (hold.empty()) {
            while(!q.empty()) {
                hold.push(q.top());
                q.pop(); 
            }
        } 
        
        int item = hold.top();
        hold.pop();
        
        size--; 
        return item; 
    }
    
   // time O(n)
    int peek() {
        if (q.empty() && hold.empty()) {
            return -1;
        }
        
        if (hold.empty()) {
            while(!q.empty()) {
                hold.push(q.top());
                q.pop(); 
            }
        } 
        
        return hold.top();
    }
    
    // time O(1)
    bool empty() {
        return (q.empty() && hold.empty());
    }
};