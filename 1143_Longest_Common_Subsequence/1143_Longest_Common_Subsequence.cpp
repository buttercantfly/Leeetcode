#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    complexity = O(nxm)

improve:
    vector好像比較慢? 比起用array的話

*/

// Class Solution copy here
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for (int i = text1.size()-1; i >= 0; i--)
        {
            for (int j = text2.size()-1; j >= 0; j--)
            {
                if(text1.at(i) == text2.at(j)) {dp[i][j] = 1 + dp[i+1][j+1];}
                else {dp[i][j] = max(dp[i+1][j], dp[i][j+1]);}
            }
        }
        return dp[0][0];
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