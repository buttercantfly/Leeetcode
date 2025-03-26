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
public:
    int minCapability(vector<int>& nums, int k) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            min = (nums[i] < min) ? nums[i] : min;
            max = (nums[i] > max) ? nums[i] : max;
        }

        while(min < max) {
            int mid = min + (max - min) / 2;
            int cnt = 0; // count of possible houses
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] < mid) {
                    cnt++;
                    j++; // skip adjacent house
                }
            }
            if(cnt >= k) {
                max = mid; // mid is "possible" so we try to find a smaller value
            } else {
                min = mid + 1; // mid is "impossible" so the value that is less than mid is impossible too
            }
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