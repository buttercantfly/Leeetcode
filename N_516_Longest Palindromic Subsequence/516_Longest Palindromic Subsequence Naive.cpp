#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    基本上都是要從中心出發(比較快可以break)
    dp 使用

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = 0;
        for (string::iterator it = s.begin();it != s.end(); it++)
        {
            int sub = 1;
            string::iterator l;
            string::iterator r;
            if(it != s.begin()) l = it - 1;
            if(it != s.end() - 1) r = it + 1;

            while (l+1 != s.begin() && r-1 != s.end() - 1)
            {
                if (*l == *r)
                {
                    l++;
                    r++;
                }
                else
                {
                    r++;
                }
            }
            
            max(sub, length);
        }
        
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