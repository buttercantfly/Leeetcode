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
    
*/

// Class Solution copy here
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int maxLength = 0;

        bool allequal = false;
        if (nums[0] == nums[1]) allequal = true;
        
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i+1]) allequal = false;
            if ((nums[i]-nums[i-1])*(nums[i+1]-nums[i]) < 0) maxLength++;
        }

        if (allequal) return 1;
        if (maxLength == 0) return 2;
        return maxLength + 2;
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