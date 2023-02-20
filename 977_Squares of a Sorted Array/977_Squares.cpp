#include <iostream>
#include <string>
#include <vector>
// #include <cmath>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

/*
note: 
    沒啥難的 用queue比大小的想法去做就好
improve:
    本題速度/使用空間有些太多 可以只使用一個vector就好
    (list是有push front比較方便 但題目要的是vector)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        for(int i = 0; i<nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }

        list<int> lt;
        int leftptr  = 0;
        int rightptr = nums.size()-1;

        while (leftptr <= rightptr)
        {
            if(nums[leftptr]>nums[rightptr]){
                lt.push_front(nums[leftptr]);
                leftptr++;
            }
            else{
                lt.push_front(nums[rightptr]);
                rightptr--;
            }
        }
        
        vector<int> ans{begin(lt), end(lt)};

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v = {-4,-1,0,3,10};
    vector<int> ans = s.sortedSquares(v);
    
    for(int i: ans){
        cout << i << ' ';
    }
    return 0;
}