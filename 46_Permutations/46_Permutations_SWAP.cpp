#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    開始 終止 過程
improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<vector<int>> result;

    void backtracking(vector<int>& nums, int index) {
        if (index == nums.size()) result.push_back(nums);
        
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            backtracking(nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
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