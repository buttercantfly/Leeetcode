#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
question:

note: 
    recursive way backtracking
    start: int recursive(string& s, splitted i)
    end 
    mid while if splitted to attempt s is not in exist_substrings then split(s, attempted+1) 
            if return value is -1 then while contiue
            if attempt>1 which means the track is invalid return -1

    ***
    you have to try out every single possibility to find the max solution
    so the return way would change
    ***

improve:
    
*/

// Class Solution copy here
class Solution {
private:
    //    -1    0 1 2 3 4 5
    // splitted 
    // 
    int split(string& s, int splitted) {
        if (splitted == s.length()-1) return 0;
        int attempt = splitted+1;
        int ret = -1;
        string part = "";
        while (attempt < s.length())
        {
            part += s[attempt];
            if (exist_substrings.count(part)) attempt++;
            else
            {
                exist_substrings.insert(part);
                ret = max(ret,split(s, attempt)+1);
                exist_substrings.erase(part);
                attempt++;
            }
        }
        return ret;
    }
public:
    unordered_set<string> exist_substrings;
    int maxUniqueSplit(string s) {
        return split(s, -1);
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