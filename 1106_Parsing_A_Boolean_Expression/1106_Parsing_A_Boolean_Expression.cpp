#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

/*
question:

note: 
    a stack for operators
    divide
    |(a,b,c)
    if(|) {
        for(i = pos'(';i < pos of')';i++){
            if(expression[i]) is t return t;
        }
        return f;
    }
    recursive?

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops;
        stack<char> exps;
        for (char c:expression)
        {
            if (c == 't' || c == 'f' || c == '(') exps.push(c);
            else if(c == ')') { // start operation
                if (ops.top() == '!')
                {
                    if(exps.top() == 't')
                    {
                        exps.pop();
                        exps.pop();
                        exps.push('f');
                        ops.pop();
                    }
                    else
                    {
                        exps.pop();
                        exps.pop();
                        exps.push('t');
                        ops.pop();
                    }
                }
                else if(ops.top() == '&')
                {
                    bool isFalse = false;
                    while (exps.top() != '(')
                    {
                        if (exps.top() == 'f') isFalse = true;
                        exps.pop();
                    }
                    exps.pop(); // pop out '('
                    if (isFalse) exps.push('f');
                    else exps.push('t');
                    ops.pop(); // finish operation
                }
                else if(ops.top() == '|')
                {
                    bool isTrue = false;
                    while (exps.top() != '(')
                    {
                        if (exps.top() == 't') isTrue = true;
                        exps.pop();
                    }
                    exps.pop(); // pop out '('
                    if (isTrue) exps.push('t');
                    else exps.push('f');
                    ops.pop(); // finish operation
                }
            }
            else if(c == '!' || c == '&' || c == '|') ops.push(c);
        }
        if (exps.top() == 't') return true;
        else return false;
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