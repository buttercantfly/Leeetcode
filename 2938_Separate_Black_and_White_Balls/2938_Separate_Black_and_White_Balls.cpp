#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

/*
question:

note: 
    1key idea: no redundant swap
 
    0000010000100010010

    0101010
    1+2+3 = 6

    2 key idea: we dont really have to swap

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    long long minimumSteps(string s) {
        long long step  = 0;
        long long zeroCounts = 0;
        long long steps = 0;
        // 
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1') 
            {
                step++;
                zeroCounts = 0;
                i++;
                while (s[i] == '0')
                {
                    zeroCounts++;
                    i++;
                }
                steps += step*zeroCounts;
                i--;
            }
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