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
    巢狀結構不優喔
    盡可能只使用if跟continue去處理

*/

// Class Solution copy here
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    if (i == 0 && j == 0) dp[i][j] = 1;
                    else if(i == 0) dp[i][j] = dp[i][j-1];
                    else if(j == 0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
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