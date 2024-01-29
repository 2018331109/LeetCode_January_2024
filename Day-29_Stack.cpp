/*
232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

SUBMISSION IN C++
*/
class MyQueue {
    private:
    stack<int>ans, temp;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!ans.empty())
        {
            temp.push(ans.top());
            ans.pop();
        }
        ans.push(x);
        while(!temp.empty())
        {
            ans.push(temp.top());
            temp.pop();
        }
        
    }
    
    int pop() {
        int v=ans.top();
        ans.pop();
        return v;
        
    }
    
    int peek() {
        return ans.top();
        
    }
    
    bool empty() {
        return ans.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
