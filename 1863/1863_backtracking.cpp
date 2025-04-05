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
private:
    int ret = 0;
    void helper(int i, int n, vector<int>& nums) {
        for(int j = i+1; j < nums.size(); j++) {
            ret += n^nums[j];
            helper(j, n^nums[j], nums);
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            ret += nums[i];
            helper(i, nums[i], nums);
        }
        return ret;
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