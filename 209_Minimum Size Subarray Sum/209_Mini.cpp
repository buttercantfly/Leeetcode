#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    Remember: get the code working with a clean interface, 
              then worry about performance.
    用FIFO的結構去紀錄(某方面來說像dp)
    不斷檢驗去增加/減少內部長度
    time complexity應該是O(n)

improve:
    速度和使用的記憶體有點差
    => 其實不需要使用另一個獨立的stl去儲存，只要用兩個指標(i,j)紀錄頭尾就好了
    => 不但空間少很多且不需花費時間執行push/ pop
*/

// Class Solution copy here
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;
        int summation = 0;
        deque<int> subarray;

        for(int i: nums){
            subarray.push_front(i);
            summation += i;
            if(!subarray.empty()){
                while(summation - subarray.back() >= target)
                {
                    summation -= subarray.back();
                    subarray.pop_back();
                    
                    if(subarray.empty()) break;
                }
            }

            if(summation >= target){
                length = min(length, (int)subarray.size());
            }
        }

        if(length == INT_MAX) length = 0;

        return length;
    }
};


// test function
int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    Solution s;
    int ans = s.minSubArrayLen(target, nums);
    cout << ans;

    return 0;
}