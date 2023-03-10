#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    一開始使用2d array去儲存情況 => memory limit exceeded
    => 只使用ret去記?

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int size = words.size();
        int ch_count[26][size];
        vector<string> ret;

        for (int s = 0; s < size; s++)
        {
            for (char& c: words[s])
            {
                ch_count[(int)c - (int)'a'][s]++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            int du = 0;
            string s(1, char((int)'a' + i)); // 這行搞超久靠北 太久沒寫char/string = =

            for (int j = 0; j < size; j++)
            {
                du = min(du, ch_count[i][j]);
            }
    
            while(du--) ret.push_back(s); // 試驗while跑指定圈數
        }

        return ret;
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