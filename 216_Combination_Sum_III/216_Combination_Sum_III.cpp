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
private:
    vector<vector<int>> ret;
    vector<int> sumation;
    int sum;
    void combine(int last_num, int nums_num, int target) {
        if (sum == target && sumation.size() == nums_num)
        {
            ret.push_back(sumation);
            return;
        }
        else if(sum >= target || sumation.size() >= nums_num) return;
        else{
            for (int i = last_num; i <= 9; i++)
            {
                sumation.push_back(i);
                sum += i;
                combine(i+1, nums_num, target);
                sumation.pop_back();
                sum -= i;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n/k >= 9) return ret;
        combine(1, k, n);
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