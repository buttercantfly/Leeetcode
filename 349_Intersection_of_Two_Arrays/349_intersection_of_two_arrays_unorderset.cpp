#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
note: 
    
improve:
    解答中沒有另外宣告vector作為回傳，而是利用iterator去做travesal
    => 結果使用的mem還更多??? why???
    => 
*/

// Class Solution copy here
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        // vector<int> res;

        for (int i: nums1)
        {
            set1.insert(i);
        }

        for (int j: nums2)
        {
            if(set1.count(j) && !set2.count(j)){
                // res.pushback(j);
                set2.insert(j);
            }
        }
        
        // return res;
        return vector<int>(set2.begin(), set2.end());
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";
    string t = "";

    // call solution function
    /*
    Solution s;
    int ans = s.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}