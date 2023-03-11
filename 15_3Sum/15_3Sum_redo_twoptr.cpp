#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
note: 
    two ptr 利用的是 答案的"range"
        a + b + c = 0
    =>  a + b = -c (其實就變成2sum的題目)
    => a,b不可能同時大於或小於-c
    => 因此我們假設a < -c < b
    => 又因上式我們可以將a設為vector中最小值、b為vector中最大值
    => |a|x|x|x|x|x|x|x|x|x|b|
    => 接下如果 a+b > -c 的話，我們需要將a+b變小，因此將b往左一格
    => |a|x|x|x|x|x|x|x|x|b|o|
    => 再接下來如果 a+b < -c 則是要將a往右一格
    => |o|a|x|x|x|x|x|x|x|b|o|
    => 依照此法不斷執行 即可找到解答

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_set<int> set;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] > 0) break;
            if(set.count(nums[i])) continue;;

            int j = i+1;
            int k = nums.size()-1;
            while (j < k)
            {
                int t = nums[j] + nums[k];
                if(t == -nums[i]) {
                    ret.push_back(vector<int> {nums[i],nums[j],nums[k]});

                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(t < -nums[i]) j++;
                else k--;
            }

            set.insert(nums[i]);
        }
        
        return ret;
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {-1,0,1,0};
    // {-2 -1 0 1 2 3}

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

    return 0;
}