#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        
        for (int i = 0; i < size; i = i + 2*k)
        {
            if(i + k <= size){
                for(int j = 0; j < k/2; j++)
                {
                    swap(s[i+j], s[i+k-1-j]);
                }
            }
            else{
                for(int j = 0; j < (size - i)/2; j++)
                {
                    swap(s[i+j], s[size-1-j]);
                }
            }
        }
        
        return s;
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