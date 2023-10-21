#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    因為回傳是長度 => 不需要紀錄index
    
improve:
    可以再精進
    1. equal state其實不需要(for迴圈內部不影響)，只需要小心all equal的情況即可
    2. 其實不需要用state去做，只要用nums[index]diff檢查就好
    3. 初始狀態也應該可以更精簡
    但留著思路也不錯 就不特別精簡code了(time complexity沒問題)

*/

// Class Solution copy here
class Solution {
private:
    int lastState; // 0 as ascending 1 as descending 2 as equal
    int subLength;
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        subLength = 2;
        if (nums[1] > nums[0]) lastState = 0;
        else if (nums[1] < nums[0]) lastState = 1;
        else {
            lastState = 2;
            subLength = 1;
        }

        int curState;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1]) curState = 0;
            else if (nums[i] < nums[i-1]) curState = 1;
            else curState = 2;

            if (curState != lastState && curState != 2) {
                lastState = curState;
                subLength++;
            }
        }
        
        if (lastState == 2) return 1; // all elements are equal (keep the State 2 to the end)
        return subLength;
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