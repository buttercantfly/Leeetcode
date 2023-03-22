#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (char c:s)
        {
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        int size = st.size();

        for (int i = size; i > 0; i--)
        {
            s[i-1] = st.top();
            st.pop();
        }
        
        s.resize(size);

        return s;
    }
};

// test function
int main(){
    // given values
    string s = "caabbaac";

    // call solution function
    
    Solution sol;
    string ans = sol.removeDuplicates(s);

    // print out answers 
    cout << ans;
    

    return 0;
}