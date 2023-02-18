#include <iostream>
#include <string>
#include <vector>
// #include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

/*
note: 
    
improve:
    
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        for(int i = 0; i<nums.size()-1; i++){
            nums[i] = nums[i]^2;
        }

        list<int> lt;
        int leftptr  = 0;
        int rightptr = nums.size()-1;

        while (leftptr < rightptr)
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
        
        // 不能用list(題目要求用vecctor= =)
        return lt;
    }
};

int main(){

    return 0;
}