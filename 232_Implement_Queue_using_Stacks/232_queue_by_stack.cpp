#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
using namespace std;

/*
question:
    Implement a first in first out (FIFO) queue using only two stacks. 
    The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

note: 
    兩個stack
    => 一個進一個出
    => 出的時候才將instack的資料丟進outstack

improve:
    其中 pop 和 peek 幾乎是一樣的，但不應該直接將它複製過去，
    應該要將相同的部分拿出來做重複調用，以此可方便使用，也使程式更加簡潔。

    此外，能減少tmp的使用就減少(也可一開始寫的時候可以先寫，之後再思考是否需要)
*/

// Class Solution copy here
class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        this->fill_inStack();

        int tmp = outStack.top();
        outStack.pop();
        
        return tmp;
    }
    
    int peek() {
        this->fill_inStack();
        
        return outStack.top();
    }
    
    bool empty() {
        if (outStack.empty() && inStack.empty()) return true;
        else return false;
    }

private:
    void fill_inStack() {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
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

// test function
int main(){
    
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    // call solution function
    /*
    Solution s;
    int ans = s.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}