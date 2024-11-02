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
    
*/

// Class Solution copy here

// erase is too slow
class Solution {
public:
    string earseMakeFancyString(string s) {
        int  cnt = 0;
        char chr = '!';
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == chr && cnt >= 2)
            {
                s.erase(it);
                it--;
            }
            else if(*it == chr && cnt < 2)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                chr = *it;
            }
        }
        return s;        
    }

// string push_back()
    string makeFancyString(string s) {
        string ret = "";
        ret += s[0];
        
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i-1]) ret.push_back(s[i]);
            else
            {
                char c = s[i-1];
                while (s[i] == c && i < s.length()) i++;
                ret.push_back(s[i-1]);
                i--;
            }
        }
        return ret;
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