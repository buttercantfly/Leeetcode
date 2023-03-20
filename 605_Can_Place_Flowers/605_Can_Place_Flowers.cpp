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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        // 頭可以算做gap = 1
        // 0 0 1 -> 1 0 1
        int last  = 0;
        flowerbed.push_back(0);

        // 找可填入最多
        for (int i = 0; i < flowerbed.size() - 1; i++)
        {
            // 連續兩個0 且 下一個為0 就可以填入
            // 1 0 0 0 1 -> 1 0 1 0 1 -> stop
            // 1 0 0 0 0 1 -> 1 0 1 0 0 1 -> stop
            // 1 0 0 0 0 0 1 -> 1 0 1 0 0 0 1 -> 1 0 1 0 1 0 1 -> stop
            //
            // 注意尾巴可以是 1 0 0 -> 1 0 1
            //
            // 出現1則gap歸零
            // 

            if(last == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                count++;
                last = 1;
            }
            else
            {
                last = flowerbed[i];
            }
            

            if (count >= n) return true;
        }
        
        return false;
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