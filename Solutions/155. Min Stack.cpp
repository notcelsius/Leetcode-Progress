// Date Completed: 12/19/2024

// Leetcode Problem: https://leetcode.com/problems/min-stack/

// Time Complexity: O(1)
// Space Complexity: O(n)

// really not much to explain here
class MinStack {
private:
    stack<int> stk; // the actual stack
    stack<int> minstk;  // keeps track of the min on the stack
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val); 
        if (minstk.empty() || minstk.top() > val)
        {
            minstk.push(val);
        }
        else
        {
            minstk.push(minstk.top());
        }
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
         return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */