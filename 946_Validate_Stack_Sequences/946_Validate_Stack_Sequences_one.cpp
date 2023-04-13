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
    這邊這個解法利用pushed 推過就不會在用到的特點
    把pushed vector前面的部份當作stack操作

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        
        for (int val: pushed)
        {
            pushed[i] = val;
            while (j >= 0 && i >= 0 && pushed[i] == popped[j])
            {
                i--;
                j++;
            }
            i++;
        }

        return i == 0;
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