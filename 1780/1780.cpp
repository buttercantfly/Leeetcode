#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool checkPowersOfThree(int n) {
        // backtracking?
        double ret = (double)n;
        
        for(double i = 0.0; pow(3.0, i) <= ret ; i++) {
            cout << i << endl;
            if((int)(ret - pow(3.0, i)) % (int)pow(3.0, i+1) == 0) {
                ret -= pow(3.0, i);
                cout << ret << endl;
            }
            if(ret == 0) {
                cout << "true" << endl;
                return true;
            }
        }
        
        return false;
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 12;
    string s = "";

    // call solution function
    
    Solution sol;
    bool ans = sol.checkPowersOfThree(target);

    // print out answers 
    cout << ans;
    

    return 0;
}