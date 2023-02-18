#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
note: 
    一樣的問題，邊界要先想好
    然後*****空集合****的情況也要想好

improve:
    解答是使用slow pointer + fast pointer
    與left/right pointer其實效率沒啥差
    => 但以code長度來說slow/fast短很多
    => 因為rightptr需要**while**去找最左的非val元素

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.empty()) return 0;

        int rightptr = nums.size()-1;

        while (nums[rightptr] == val) {
            rightptr--;
            if(rightptr == -1) return 0;
        }

        for(int leftptr = 0; leftptr <= rightptr; leftptr++){
            if(nums[leftptr] == val){
                nums[leftptr] = nums[rightptr];
                rightptr--;
                while (nums[rightptr] == val) {
                    if(rightptr == -1) return 0;
                    rightptr--;
                }
            }
        }

        return rightptr+1;
    }
};

int main(){

    return 0;
}