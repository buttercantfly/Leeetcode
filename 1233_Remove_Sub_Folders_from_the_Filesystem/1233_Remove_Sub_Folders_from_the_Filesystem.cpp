#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
question:

note: 
    hashmap?
    parent and children sets?
    how to make sure that we put strings from root to pedestrians?

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    unordered_set<string> set;
    vector<string> removeSubfolders(vector<string>& folder) {
        // hashmap?
        for (string s:folder)
        {
            set.insert(s);
        }
        
        for (string s:folder)
        {
            string folder_name = "";
            int lastEnd = 0;
            int i = 1;
            for (; i < s.length(); i++)
            {
                // if (i == s.length()-1) set.insert(s);
                if (s[i]=='/') {
                    for (int j = lastEnd; j < i; j++) folder_name += s[j];
                    if (set.count(folder_name)) {
                        set.erase(s);
                        break;
                    }
                    lastEnd = i;
                }
            }
        }
        
        vector<string> ret_vec;
        for (const auto& elem: set)
        {
            ret_vec.push_back(elem);
        }
        
        return ret_vec;
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