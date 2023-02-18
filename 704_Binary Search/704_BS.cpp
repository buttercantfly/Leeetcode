#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
note: 
    在邊界設置上要先想好，不然要一直debug，
    尤其是在找到邊界的如index 0,end等的情況
    以及沒元素或只有一個元素的array中要如何處理(會不會出事)

improve:
    需要做recursive嗎? 其實迴圈就夠了
    (更改pivot/leftbound/rightbound的數值就好)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size() - 1, target);
    }

    int binarysearch(vector<int>& nums, int leftbound, int rightbound, int target){
        if(leftbound > rightbound) return -1;

        int p_index = (leftbound+rightbound)/2;
        int pivot = nums[p_index];

        if(pivot > target)       return binarysearch(nums, leftbound, p_index-1, target);
        else if (pivot == target) return p_index;
        else                     return binarysearch(nums, p_index+1, rightbound, target);
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    Solution s;
    cout << s.search(nums, target);

    return 0;
}