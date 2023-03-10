#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
note: 
    就簡單的用ASCII去做hash就好(26 buckets)
improve:
    可能不會比較快 不過比較直覺的是用 c - 'a' 代替c - 97
    
*/

// Class Solution copy here

class Solution {
public:
    bool isAnagram(string s, string t) {
        int set[26] = {0};

        for (char& c:s)
        {
            set[((int)c-97)]++;
        }

        for (char& c:t)
        {
            set[((int)c-97)]--;
        }

        for (int i: set)
        {
            if(i!=0) return false;
        }

        return true;
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