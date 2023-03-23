#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
question:

note: 
    
improve:
    用簡單判斷式子處理
    不要搞什麼stoi itos
    會造成速度大幅下降

*/

// Class Solution copy here
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        int a;
        int b;

        for (string i:tokens)
        {
            if (i == "+" || i == "-" || i == "*" || i == "/")
            {
                a = (s.top());
                s.pop();
                b = (s.top());
                s.pop();

                char op = i[0];

                if (i == "+") s.push(b + a);
                if (i == "-") s.push(b - a);
                if (i == "*") s.push(b * a);
                if (i == "/") s.push(b / a);
            }
            else
            {
                s.push(stoi(i));
            }
        }

        return s.top();
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";

    // call solution function
    /*
    Solution sol;
    int ans = sol.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}