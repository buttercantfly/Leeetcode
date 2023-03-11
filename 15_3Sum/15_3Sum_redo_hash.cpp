#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
note: 
    sort + two pointer => O(nlogn) + O(n^2)
    hash table => O(n^2) + O(n)
    不過由於題目中"不得使用重複元素"的條件存在，因此在實作hash的時候很麻煩
    (對比454 4Sum，裡面是有四個vector<int>去做組合，因此簡單用hash table即可)

improve:
    
*/

// Class Solution copy here

// 本題是直接抄解答演示 hash 解法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// 三元组元素c去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {-1,0,1,2,-1,-4};
    int target = 0;

    // call solution function
    
    Solution s;
    vector<vector<int>> ans = s.threeSum(nums);

    for (vector<int> i: ans)
    {
        cout << "[" ;
        for (int j: i)
        {
            cout << j << ", ";
        }
        cout << "] ";
    }
    

    // print out answers 
    // cout << ans;
    // [[-1,-1,2],[-1,0,1]]

    return 0;
}