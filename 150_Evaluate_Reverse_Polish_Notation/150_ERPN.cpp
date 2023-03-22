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
    有點慢? 且記憶體用很多
    => 因為用到unordered set?

*/

// Class Solution copy here
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        unordered_set<string> set;
        set.insert("+");
        set.insert("-");
        set.insert("*");
        set.insert("/");

        int a;
        int b;

        for (string i:tokens)
        {
            if (set.count(i))
            {
                a = stoi(s.top());
                s.pop();
                b = stoi(s.top());
                s.pop();

                char op = i[0];

                switch (op)
                {
                case '+':
                    s.push(to_string(b+a));
                    break;
                case '-':
                    s.push(to_string(b-a));
                    break;
                case '*':
                    s.push(to_string(b*a));
                    break;
                case '/':
                    s.push(to_string(b/a));
                    break;
                
                default:
                    break;
                }
            }
            else
            {
                s.push(i);
            }
        }

        return stoi(s.top());
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