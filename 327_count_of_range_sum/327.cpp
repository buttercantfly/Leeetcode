#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        printf("hi");
        int i;
        int j;
        
        int size = nums.size();
        vector<int> presum(size+1, 0);

        // find pre sum: O(n)
        presum[0] = 0;
        for(i = 1;i < nums.size();i++){
            presum[i] = presum[i-1]+ nums[i-1];
        }

        // 暴力 check range sums: O(n^2/2)
        /* int count = 0;
        for(i = 0;i < nums.size();i++){
            if(presum[j] >= lower && presum[j] <= upper){
                count++;
            }
            for(j = i+1;j < nums.size();j++){
                int rangeSum = presum[j] - presum[i];
                if(rangeSum >= lower && rangeSum <= upper){
                    count++;
                }
            }
        } */
        
        // 好解 => 先經過sort(O(nlogn))再用two pointer找和(O(n))
        // 複習: two sum => two pointer or hash map
        
        // 找符合的和的數量(只有數量而已)
        int count = 0;
        int pivot;
        int min;
        int max;

        for(pivot = 0;pivot < presum.size()-1;pivot++){
            int a = presum[pivot];

            for(max = presum[-1];max > pivot;max--){
                if(presum[max] - a <= upper) break;
            }
            for(min = presum[pivot+1];min < max;min++){
                if(presum[min] - a >= lower) break;
            }

            count += (max - min + 1);
        }

        printf("%d",count);

        return count;
    }

    int merge(vector<int>& nums, int lower, int upper){
        int size = nums.size()
        vector<int> left;
        vector<int> right;
        if(size == 1){
            return nums[0];
        }else{
            left = size/2
        }
        return merge(nums, lower, upper);
    }
};

int main() {
    printf("??");
    Solution sol;
    
    vector<int> nums  = {-2,5,-1};
    int         lower = -2;
    int         upper =  2;

    sol.countRangeSum(nums, lower, upper);
}

// 先想整個流程會是如何?
/*
    1. 把range sum找出來
    2. 跟upper與lower比較(sort?)
*/

// 可以直接找出來嗎?

// 暴力法 
// 用i j 兩個index 去scan整個list

// 遞迴法 iteration
// 先想怎麼找rangesum()
// => 用遞迴方式不斷呼叫小部分，
// 如rangesum(1,3)則呼叫rangesum(1,2)和rangesum(3,3)
// 而rangesum再呼叫(1,1)跟(2,2)

// 這樣有效率嗎? 並沒有

// 但可以用這個方法去建構一個樹狀結構
// 其leaf為相鄰的兩數相加e.g.(0,1) (1,2) (2,3) => 寬度為n-1
// 