#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    this is a backtracking solution
    it works but TLE
    
improve:
    
*/

// Class Solution copy here
class Solution {
    private:
        // i is taken, k is remaining houses
        void helper(vector<int>& nums, int i, int k) {
            if(k == 0) {
                if(curMax < min) min = curMax;
                return;
            } 
            for(int j = i + 2; j < nums.size(); j++) {
                int tmp = curMax;
                curMax = (nums[j] > curMax) ? nums[j] : curMax;
                helper(nums, j, k-1);
                curMax = tmp;
            }
        }
    public:
        int min = INT_MAX;
        int curMax = INT_MIN;
        int minCapability(vector<int>& nums, int k) {
            // naive: backtracking 
            // works but -> TLE
            // 
            // dp?
            for(int i = 0; i < nums.size(); i++) {
                curMax = nums[i];
                curMax = (nums[i] > curMax) ? nums[i] : curMax;
                helper(nums, i, k-1);
                curMax = (nums[i] < curMax) ? nums[i] : curMax;
            }
            return min;
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