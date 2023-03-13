#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    string實際上是一個char array
    其為一個指標指向char的頭

    本題難點在於只能使用額外O(1)的space
    
    swap? swap!

improve:
    可以使用swap函數
    
*/

// Class Solution copy here
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int size = s.size();
        for (int i = 0; i < size/2; i++)
        {
            tmp = s[i];
            s[i] = s[size-1-i];
            s[size-1-i] = tmp;
        }
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