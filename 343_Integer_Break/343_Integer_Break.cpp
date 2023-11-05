#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:
    Given an integer n, break it into the sum of k positive integers, 
    where k >= 2, and maximize the product of those integers.

    Return the maximum product you can get.

note: 
    break down
    divide and conquer?

    為什麼需要dp?
    因為拆分成小部分後可以從已經算過的dp去把max product抓出來 
    
    2 = 1+1 => 1*1 = 1
    2 = 2+0 x

    3 = 1+2 => 1*2 = 2
    3 = 2+1 x

    4 = 1+3 => 1*3 = 3
    4 = 2+2 => 2*2 = 4
    4 = 3+1 x

    5 = 1+4 => 1*4 = 4
    5 = 1+(4去拆) => 1*4 = 4
    5 = 2+3 => 2*3 = 6
    5 = 3+2 x

    1. 要注意取dp如果數字本身比拆後max product還大，那就直接取自己就好
    2. 什麼時候停止?
        如果拆後出現當前的部分>後拆出來的部分即停止
        why? 因為我們是從小的數字開始拆分，如果拆到比較大的，就表示後面拆出來的那個部分前面已經拆過了

improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<int> dp = {0,1,2,3};

public:
    int integerBreak(int n) {
        // n >= 2 所以不需要考慮0和1的情況
        if (n < 4) return n-1;
        
        // 外圈從1開始，一路dp到n
        for (int i = 4; i <= n; i++) // i = 4
        {
            int iMax = i; // 3
            for (int j = 1; j <= i/2; j++) // j = 2
            {
                if (dp[j]*dp[i-j] > iMax) iMax = dp[j]*dp[i-j];
            }
            dp.push_back(iMax);
        }
        return dp[n];
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 10;
    string s = "";

    // call solution function
    Solution sol;
    int ans = sol.integerBreak(target);

    // print out answers 
    cout << ans;

    return 0;
}