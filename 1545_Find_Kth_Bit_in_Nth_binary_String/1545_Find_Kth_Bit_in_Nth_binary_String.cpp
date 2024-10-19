#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    first try recursive way to do so
    (naive)
    如果要最快的話就是數學解法

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    char findKthBit(int n, int k) {
        string nth_string = "0";
        string reversed_string = nth_string;
        while (n--)
        {
            reversed_string = nth_string;
            for (int i = 0; i < reversed_string.length(); i++)
            {
                if (reversed_string[i] == '0') reversed_string[i] = '1';
                else reversed_string[i] = '0';
            }
            reverse(reversed_string.begin(), reversed_string.end());
            nth_string = nth_string + "1" + reversed_string;
        }
        return nth_string[k-1];
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.findKthBit(4,11);

    // print out answers 
    cout << (char)ans;
    

    return 0;
}