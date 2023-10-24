#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    他其實只看能不能到結尾=>其實小心0就可以
improve:
    不需要搞那麼多有的沒的，只要不斷擴張farPos其實就可以了
*/

// Class Solution copy here
class Solution {
private:
    int curPos = 0;
    int farPos = 0;

public:
    bool canJump(vector<int>& nums) {
        farPos = nums[0]; // initialization
        while (curPos < nums.size()-1)
        {
            int curFarPos = farPos;
            for (int i = curPos + 1; i <= curFarPos && i < nums.size(); i++)
            {
                if (i + nums[i] >= farPos)
                {
                    farPos = i + nums[i];
                    curPos = i;
                }
            }
            if (farPos >= nums.size() - 1) return true;
            if (curPos == farPos) return false;
        }
        return true;
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