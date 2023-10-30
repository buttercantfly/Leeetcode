#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:
    題目一定能到達nums[n-1]
    回傳最少步數

note: 
    =>回傳擴展farPos的次數即可
    =>可以用每次到下一步時找到可以到最遠的位置
    如:
    [2 3 1 1 4 0 0 1]
    第一圈 farPos = 4 (代表選擇nums[1]做為第一步的落點)
    第二圈 farPos = 7 (代表選擇nums[4]做為第一步的落點)

    如果第一步就到終點?
    fix bug (boundary situation)

    重來
    開始 終止 過程
    開始: farPos = 0 steps = 0

    終止: 如果 farPos 已經到 n-1 => end
    
    過程: 用farPos內最大的能到達的地方更新farPos

improve:
    
*/

// Class Solution copy here
class Solution {
private:
    int curPos = 0;
    int farPos = 0;
    int steps  = 1;
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        farPos = nums[0]; // initialization
        while (farPos < nums.size()-1)
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
            steps++;
        }
        return steps;
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