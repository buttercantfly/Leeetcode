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
    unordered_set<int> used_set; // 這裡的是index是否使用過

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        
        unordered_set<int> level_set; // 這裡則是該數字nums[i]是否使用過
        for (int i = 0; i< nums.size();i++)
        {
            if (!used_set.count(i))
            {
                if (!level_set.count(nums[i]))
                {
                    path.push_back(nums[i]);
                    used_set.insert(i);
                    level_set.insert(nums[i]);
                    backtracking(nums);
                    path.pop_back();
                    used_set.erase(i);
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtracking(nums);
        return result;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {2,2,1,1};

    Solution sol;
    vector<vector<int>> ret = sol.permuteUnique(nums);
    cout << "result" << endl;
    for (vector<int> v:ret)
    {
        for (int i:v)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}