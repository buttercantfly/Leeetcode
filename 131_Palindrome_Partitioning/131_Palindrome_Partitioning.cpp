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
    主要可以針對 is_palindrome 的部分進行優化，利用雙指針/dp演算法可以增進時間複雜度
*/

// Class Solution copy here
class Solution {
private:
    vector<vector<string>> ret;
    vector<string> cur_partition;

    void backtracking(string s) {
        if (s.length() == 0) ret.push_back(cur_partition);

        string current_part;
        
        for (int i = 0; i < s.length(); i++)
        {
            current_part += s[i];
            if (is_palindrome(current_part))
            {
                cur_partition.push_back(current_part);
                backtracking(s.substr(i+1, s.length()));
                cur_partition.pop_back();
            }
        }
    }

    bool is_palindrome(string s)
    {
        for (int i = 0; i < s.length()/2; i++)
        {
            if (s[i] != s[s.length()-i-1]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s);

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