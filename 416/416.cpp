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
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i: nums) total += i;
        if(total%2 != 0) return false;
        vector<bool> dp(total/2+1, false);
        dp[0] = true;
        for(int i: nums) {
            for(int j = total/2; j-i >= 0; j--) {
                if(dp[j-i] == true) dp[j] = true;
            }
            if(dp[total/2] == true) return true;
        }
        return false;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {1,5,11,5,1};
    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    bool ans = sol.canPartition(nums);

    // print out answers 
    cout << ans;

    return 0;
}