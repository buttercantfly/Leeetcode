#include <vector>
#include <iostream>

// Dp
// O(n)

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int max = 0;
        int tmp;

        if(nums.size() == 1) return nums[0];
        
        for(int i = 0;i < nums.size();i++) {

            if(nums[i]  < 0){
                std::swap(pos, neg);
            }

            if(nums[i] == 0){
                pos, neg = 0, 0;
            }

            pos = std::max(pos*nums[i], nums[i]);
            printf("%d\n", pos);
            neg = std::min(neg*nums[i], nums[i]);
            printf("%d\n", neg);
            tmp = std::max(pos, neg);
            max = std::max(tmp, max);
            printf("%d\n", max);
        }

        return max;
    }
};

int main(){

    Solution sol;
    std::vector<int> nums = {-2};
    
    sol.maxProduct(nums);

    return 0;
}