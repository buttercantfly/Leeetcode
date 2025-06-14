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
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        
        int ones = 0, zeros = 0, retMax = 1;
        for(string s: strs) {
            ones = 0, zeros = 0;
            for(char c: s) {
                if(c == '0') zeros++;
                else ones++;
            }
            for(int i = m; i >= 0; i--) {
                for(int j = n; j >= 0; j--) {
                    if(dp[i][j] > 0) // which means it is a possible solution
                    {
                        if(i+zeros > m || j+ones > n) continue;
                        dp[i+zeros][j+ones] = max(dp[i+zeros][j+ones], dp[i][j]+1);
                        retMax = max(retMax, dp[i+zeros][j+ones]);
                    }
                }
            }
        }

        return retMax - 1;
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