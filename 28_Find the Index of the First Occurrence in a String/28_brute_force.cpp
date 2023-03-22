#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    本題先用brute force方式解

improve:
    使用kmp算法
*/

// Class Solution copy here
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++)
        {
            for (int j = 0; j < needle.size(); j++)
            {
                if (j == haystack.size()) break;
                
                if(haystack[i+j] == needle[j]);
                else break;

                if (j == needle.size() - 1) return i;
            }
        }
        return -1;
    }
};

// test function
int main(){
    // given values
    string haystack = "ab";
    string needle = "ab";

    // call solution function
    
    Solution sol;
    int ans = sol.strStr(haystack, needle);

    // print out answers 
    cout << ans;
    

    return 0;
}