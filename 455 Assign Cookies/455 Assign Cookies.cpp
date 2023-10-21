#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    g is children's greed factor
    s is sizes of cookies
    => 最大的餅乾給最飢渴的小朋友(滿足當下最多)

    局部最優->全局最優

improve:
    不需要sum的存在，利用index的關係?
*/

// Class Solution copy here
class Solution {
private:
    int sum = 0;

public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = g.size() - 1, j = s.size() - 1; i >= 0 && j >= 0; i--)
        {
            if (g[i] <= s[j])
            {
                sum++;
                j--;
            }
        }

        return sum;
    }
};

// test function
int main(){
    // given values
    vector<int> greed = {1,2};
    vector<int> sizec = {1,2,3};

    // call solution function

    cout << "break point here" << endl;
    
    Solution sol;
    int ans = sol.findContentChildren(greed, sizec);

    // print out answers 
    cout << ans << endl;
    

    return 0;
}