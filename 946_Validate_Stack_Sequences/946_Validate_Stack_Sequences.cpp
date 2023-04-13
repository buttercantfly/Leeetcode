#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

/*
question:
    Given two integer arrays pushed and popped each with distinct values, 
    return true if this could have been the result of
    a sequence of push and pop operations on 
    an initially empty stack, or false otherwise.

    All the elements of pushed are unique.
    popped.length == pushed.length
    popped is a permutation of pushed.
 
note: 
    作筆記啦 凡死
    1. push到top和opped一樣
    2. 如果top和opped一樣就pop掉
    3. 如果top和opped不一樣就break ()


improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pushed_f = 0;
        int poped_f = 0;
        int size = pushed.size();

        if (pushed.empty()) return true;
        else st.push(pushed[pushed_f]);
        
        while (poped_f < size && pushed_f < size)
        {
            if ((st.empty() || st.top() != popped[poped_f]) && pushed_f+1 < size)
            {
                pushed_f++;
                st.push(pushed[pushed_f]);
            }
            else if (st.top() == popped[poped_f]) // st 不空 且st.top == popped
            {
                st.pop();
                poped_f++;
            }
            else break;
        }
        
        if (st.empty()) return true;
        else return false;
    }
};

// test function
int main(){
    // given values
    vector<int> pushed = {3,0,1,2};
    vector<int> poped = {2,3,1,0};

    // call solution function
    
    Solution sol;
    bool ans = sol.validateStackSequences(pushed, poped);

    // print out answers 
    cout << ans;

    return 0;
}