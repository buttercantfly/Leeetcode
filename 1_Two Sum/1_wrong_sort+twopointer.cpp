#include <vector>
#include <algorithm>

/*
    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.

    1. 只有一組解
    2. 不會用到重複元素

    => two pointer

    全錯 這樣你沒辦法配到原本的indexㄏㄏ

    問題在於return的是index不是value 如果是value就可以這樣做
    時間複雜度會是O(NlogN)

*/

class Solution {
public:
    std::vector<int> res;
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());

        int i = 0;
        int j = nums.size() - 1;

        for(; j > 0;j--){
            if(nums[j] < target){
                int sum = nums[i] + nums[j];
                do
                {
                    if(sum < target) {
                        i++;
                    }
                    else if (sum > target)
                    {
                        j--;
                    }
                    else break;

                    sum = nums[i] + nums[j];
                } while(i!=j);
                
                res = {i, j};
                return res;
            }
        }

        return res;
    }
};