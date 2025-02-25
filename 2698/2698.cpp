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
    bool split_sum_pub(int target, int k) {
        if(target == k) return true;
        else if(target < 0 || k == 0) return false;

        int divider = 10;

        while(k / divider >= 1) {
            if(split_sum_pub(target - k % divider, k / divider)) return true;
            else divider *= 10;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int iret = 1;
        for(int k = 2; k <= n; k++) {
            if(split_sum_pub(k, k*k)) iret += k*k;
        }
        return iret;
    }
};

bool split_sum_pub(int target, int k) {
        if(target == 0 && k == 0) return true;
        else if(target < 0 || k == 0) return false;

        int divider = 10;

        while(k / divider >= 1) {
            if(split_sum_pub(target - k % divider, k / divider)) return true;
            else divider *= 10;
        }
        return false;
}

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 10;
    string s = "";

    // call solution function
    Solution sol;
    bool test = sol.split_sum_pub(9, 81);
    cout << test << endl;
    int ans = sol.punishmentNumber(10);

    // print out answers 
    cout << ans;
    
    return 0;
}