class MyStack {
public:
    queue<int> stk;         
    int size; 
    
    MyStack() {
        size = 0; 
    }
    
    // time O(1)
    void push(int x) {
        size++; 
        stk.push(x);        
    }
    
    // time O(1)
    int pop() {
        if (stk.empty()) 
            return -1; 
        
        queue<int> hold;    // store elements to get to back of queue
        
        // pop until last element is left
        int count = 0; 
        while (count < size - 1) {
            hold.push(stk.front());
            stk.pop();
            count++; 
        }
        
        // store top element
        int top = stk.back();
        
        // pop top element
        stk.pop(); 
        size--; 
        
        // restore queue
        while (!hold.empty()) {
            stk.push(hold.front());
            hold.pop(); 
        }
        
        return top; 
    }
    
    // time O(1)
    int top() {
        if (stk.empty()) 
            return -1; 
        
        // retrieve top element
        int top = stk.back();
        
        return top; 
    }
    
    // time O(1)
    bool empty() {
        return stk.empty(); 
    }
};
