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
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            // why greedy cant work
            // later

            // dp
            // amount   : 1 2 3
            // c amount : 1 1 2
            vector<int> c_count(amount, -1);

            for(int i = 0; i < amount; i++) {
                for(int j : coins) {
                    if(j > i + 1) continue;
                    if(j == i + 1) c_count[i] = 1;
                    else if(c_count[i-j] != -1 && c_count[i] == -1) {
                        c_count[i] = c_count[i-j] + 1; 
                    }
                    else if(c_count[i-j] != -1) {
                        c_count[i] = min(c_count[i], c_count[i-j] + 1);
                    }
                }
            }
            return c_count[amount-1];
        }
    };

// test function
int main(){
    // given values
    vector<int> nums = {1};
    int target = 5;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.coinChange(nums, target);

    // print out answers 
    cout << ans;
    

    return 0;
}