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
    int minimumMountainRemovals(vector<int>& nums) {
        
        // left heap
        int ascend_min = 0;
        int current_max = -1;
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > current_max)
            {
                current_max = nums[i];
            }
            else {
                ascend_min++;
                current_max = nums[i];
            }
            dp[i] = ascend_min;
        }
        int ret_min = INT_MAX;
        int descend_min = 0;
        current_max = -1;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (nums[i] > current_max)
            {
                current_max = nums[i];
            }
            else {
                current_max = nums[i];
                descend_min++;
            }
            if(dp[i]+descend_min < ret_min) ret_min = dp[i]+descend_min;
        }
        return ret_min;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {4,3,2,1,1,2,3,1};

    // call solution function
    
    Solution sol;
    int ans = sol.minimumMountainRemovals(nums);

    // print out answers 
    cout << ans;
    

    return 0;
}