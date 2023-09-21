#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    
improve:
    1. 複雜index請先畫圖
    2. substr的使用方式
    3. 判斷式有些太多=>減少多餘的判斷
*/

// Class Solution copy here
class Solution {
private:
    vector<string> ret;
    string str;
    void backtracking(string s, int startIndex, int remainDot) {
        if (remainDot == 1 && s.length() - startIndex <= 3)
        {
            string tmp = s.substr(startIndex, s.length() - startIndex);
            if (s[startIndex] - 48 == 0 && s.length() - startIndex > 1) return;
            if (stoi(tmp) <= 255) ret.push_back(str + tmp);
            return;
        }
        if (remainDot == 0 && startIndex != s.length()) return;
        if (remainDot != 0 && startIndex >= s.length()) return;

        for (int i = startIndex + 1; i < startIndex + 4; i++)
        {
            if (i >= s.length()) return;
            string tmp = s.substr(startIndex, i - startIndex);
            if (stoi(tmp) > 255) return;            
            str += s.substr(startIndex, i - startIndex);
            str += ".";
            backtracking(s, i, remainDot - 1);
            if (stoi(tmp) == 0) return;
            str = str.substr(0, startIndex + (4 - remainDot));
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 4);
        return ret;
    }
};

// test function
int main(){
    // given values
    string s = "25511201105";

    // call solution function
    Solution sol;
    vector<string> ans = sol.restoreIpAddresses(s);
    cout << ans.size();

    // print out answers 
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << endl;
        cout << ans[i] << endl;
    }

    return 0;
}