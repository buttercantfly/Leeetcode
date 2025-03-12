#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cassert>
using namespace std;

/*
question:

note: 
    特殊的 binary search algorithm
    我自己覺得比較像是 "squeeze" technic

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        // to me its not like binary search
        // its more like a "squeeze" algorithm
        // similar to the calculas's squeeze technic
        while(l < r) {
            mid = (l+r)/2;
            assert(nums[mid] != nums[mid+1]); // should not happen
            // why not use mid - 1? 
            // because c++ division make the integer goes to floor
            // it is more convenient to use +1 vs -1
            if(nums[mid] > nums[mid+1]) r = mid;
            else l = mid + 1;
        }
        return l;
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