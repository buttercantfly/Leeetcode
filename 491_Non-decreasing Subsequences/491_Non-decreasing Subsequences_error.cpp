#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
question:

note: 
    為什麼這樣操作會出錯??
    => [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]
    ?
    
improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> vec;
    unordered_set<int> set;

    void backtracking(vector<int>& nums, int startIndex) {
        
        if (vec.size() >= 2) ret.push_back(vec);

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (vec.size() == 0)
            {
                vec.push_back(nums.at(i));
                backtracking(nums, i+1);
                set.insert(nums[i]);
                vec.pop_back();
            }
            else if(nums.at(i) >= vec.back() && !set.count(nums[i]))
            {
                vec.push_back(nums.at(i));
                backtracking(nums, i+1);
                set.insert(nums[i]);
                vec.pop_back();
            }
            else continue;
        }

        set.clear();
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2) return ret;
        backtracking(nums, 0);
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