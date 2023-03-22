#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
question:

note: 
    其實很無腦，把一個當backqueue就好了
    每次要top或pop就是把除了top以外所有int丟到backupqueue
    然後再restore回去即可

improve:
    
*/

// Class Solution copy here
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        
        this->backup();
        
        int tmp = que1.front();

        this->clean();

        return tmp;
    }
    
    int top() {

        this->backup();
        
        int tmp = que1.front();
        que2.push(que1.front());

        this->clean();
        
        return tmp;
    }
    
    bool empty() {
        if (que1.empty()) return true;
        else return false;
    }

private:
    void backup() {
        while (que1.size() > 1)
        {
            que2.push(que1.front());
            que1.pop();
        }
    }

    void clean() {
        que1.pop();
        que1 = que2;
        while (!que2.empty())
        {
            que2.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// test function
int main(){
    // given values
    MyStack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    // call solution function
    /*
    Solution s;
    int ans = s.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}