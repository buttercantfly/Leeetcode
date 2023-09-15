#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
question:

note:
    操你的分號= =

improve:
    不需要用到unordered_map
    因為就照數字排對應的按鈕就好
*/

// Class Solution copy here
class Solution {
private:
    vector<string> ret;
    string str = "";
    vector<string> map = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void Combiner(int current, string digits) {
        if (digits.length() == 0) return;
        
        if (current == digits.length())
        {
            ret.push_back(str);
            return;
        }

        string cur_button = map.at(digits[current]-48);
        for (auto it = cur_button.begin(); it != cur_button.end(); it++)
        {
            str = str + *it;
            Combiner(current + 1, digits);
            str.erase(str.end()-1);
        }
    }

public:
    
    vector<string> letterCombinations(string digits) {
        Combiner(0, digits);
        return ret;
    }
};

// test function
int main(){
    // given values
    string s = "23";

    // call solution function
    Solution sol;
    vector<string> ans = sol.letterCombinations(s);

    // print out answers 
    for (string sss:ans)
    {
        cout << sss << endl;
    }

    return 0;
}