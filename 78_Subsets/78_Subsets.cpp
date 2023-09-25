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
    vector<vector<int>> result; // 返回值 all subsets
    vector<int> path; // 單個subset
    void backtracking(vector<int>& nums, int startIndex) {
        if (startIndex == nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            result.push_back(path); // 每一種可能都要記錄
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(path);
        backtracking(nums, 0);
        return result;
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