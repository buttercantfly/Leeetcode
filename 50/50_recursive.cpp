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
        if(n == 0) return 1;
        if(n < 0) {
            if(n == INT_MIN) return 1/x * myPow(1/x, abs(n+1));
            return myPow(1/x, abs(n));
        }
        if(n % 2 == 0) return myPow(x*x, n/2);
        else return myPow(x*x, n/2) * x;
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