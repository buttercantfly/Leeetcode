#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cur = 0;
        int max = 0;
        for(int pr = 0; pr < 24; pr++) {
            cur = 0;
            int k = pow(2,pr);
            for(int i:candidates) {
                if((k & i) > 0) {cur++;}
            }
            if(cur > max) max = cur;
        }

        return max;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {16,17,71,62,12,24,14};
    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.largestCombination(nums);

    // print out answers 
    cout << ans;
    

    return 0;
}