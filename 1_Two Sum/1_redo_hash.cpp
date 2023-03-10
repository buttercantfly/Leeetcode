#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // values as keys and index as values
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if(map.count(nums[i])){
                ret.push_back(map[nums[i]]);
                ret.push_back(i);
                return ret;
            }
            else{
                map[target - nums[i]] = i;
            }
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
    string t = "";

    // call solution function
    /*
    Solution s;
    int ans = s.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}