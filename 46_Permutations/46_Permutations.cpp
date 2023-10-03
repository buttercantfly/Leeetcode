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
    vector<int> path;
    unordered_set<int> used_set;

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i:nums)
        {
            if (!used_set.count(i))
            {
                path.push_back(i);
                used_set.insert(i);
                backtracking(nums);
                path.pop_back();
                used_set.erase(i);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums);
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