#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here

// it's actaully a math problem (算是一種找規律)
// looking for a pattern in the problem
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total |= num;  // Step 1: Compute bitwise OR of all numbers
        }
        // total * 2^(n-1) is the answer
        return total * (1 << (nums.size() - 1));  // Step 2: Multiply by 2^(n-1)
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