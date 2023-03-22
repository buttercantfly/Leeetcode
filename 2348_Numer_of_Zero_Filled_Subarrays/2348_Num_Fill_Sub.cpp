#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    Observation:
        0 -> 1
        00 -> 2+1 = 3
        000 -> 3+2+1 = 6
        0000 -> 4+3+2+1 = 10
        00000 -> 5+4+3+2+1 = 15

    conclusion => continuous 0 array with length n has ((n+1)n)/2 subarrays

    => program only have to remember how many 0 arrays and there corresponding length
    => or even compute after 0 array end (saving memory)

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ret = 0;
        long long l_z = 0;

        for (long long i = 0; i < nums.size(); i++)
        {
            l_z = 0;
            while (nums[i] == 0 && i < nums.size())
            {
                l_z++;
                i++;
                if (i == nums.size()){
                    ret += ((l_z+1)*l_z)/2;
                    break;
                }
                else if (nums[i] != 0) ret += ((l_z+1)*l_z)/2;
            }
        }
        
        return ret;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0,1,0,0,1,0,0,0};

    // call solution function
    
    Solution sol;
    int ans = sol.zeroFilledSubarray(nums);

    // print out answers 
    cout << ans;
    

    return 0;
}