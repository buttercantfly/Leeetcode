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

    ****** 盡量用檢查是否為空代替num檢查 ******
    
    => 這題就出現 st.top() 放在num檢查後面還是被compiler讀到的問題 

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        
        for (int i: pushed)
        {
            st.push(i);
            while (!st.empty() && popped[j] == st.top())
            {
                st.pop();
                j++;
            }
        }
        
        return st.empty();
    }
};

// test function
int main(){
    // given values
    vector<int> pushed = {1,0};
    vector<int> poped = {0,1};

    // call solution function
    
    Solution sol;
    bool ans = sol.validateStackSequences(pushed, poped);

    // print out answers 
    cout << ans;

    return 0;
}