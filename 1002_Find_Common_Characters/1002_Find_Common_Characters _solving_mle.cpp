#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    如何減少記憶體使用?
    => 不要用wordsize作為col(會造成記憶體使用過多)

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int size = words.size();
        int ch_count[26];
        int tmp[26];
        std::fill_n(ch_count, 26, 0);
        std::fill_n(tmp, 26, 0);
        vector<string> ret;

        for (int s = 0; s < size; s++)
        {
            for (char& c: words[s])
            {
                tmp[(int)c - (int)'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                if(s == 0){
                    ch_count[i] = tmp[i];
                }

                if(tmp[i] < ch_count[i]){
                    ch_count[i] = tmp[i];
                }
            }

            std::fill_n(tmp, 26, 0);
        }

        for (int i = 0; i < 26; i++)
        {
            string s(1, char((int)'a' + i));
            for (int ct = 0; ct < ch_count[i]; ct++)
            {
                ret.push_back(s);
            }
        }

        return ret;
    }
};



// test function
int main(){
    // given values
    vector<string> str = {"cool","lock","cook"};
    int target = 0;

    // call solution function
    
    Solution s;
    vector<string> ans = s.commonChars(str);

    // print out answers 
    for(string t: ans)
    {
        cout << t << ", "; 
    }

    return 0;
}