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
    double myPow(double x, int n) {
        if(n == 0) return 1.0;

        bool isNeg = false;
        if(n < 0) isNeg = true;

        if(x == 1.0) return 1.0;

        int twoPow = 0;
        int sinPow = 0;
        long long _p = 2;
        int _n = n;

        while(_n/2 != 0 || _n%2 != 0) {
            if(_n/ 2 != 0) twoPow++;
            _n /= 2;
            if(_n == 1 || _n == -1) break;
        }

        for(int i = 0; i < twoPow-1; i++) {
            _p *= 2;
        }

        if(isNeg) sinPow = (-_p) - n;
        else sinPow = n - _p;

        double ret = x;
        if(isNeg) ret = 1/ret;
        for(int i = 0; i < twoPow; i++) {
            ret *= ret;
        }
        double y = x;
        if(isNeg) y = 1/y;
        for(int i = 0; i < sinPow; i++) {
            ret *= y;
            if(ret == 0) return ret;
        }
        // divide and conquer

        return ret;
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