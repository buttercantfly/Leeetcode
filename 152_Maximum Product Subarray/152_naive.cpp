#include <vector>

// naive approach
// time complexity = O(n^2)
// n + (n-1) + (n-2) ... + 1 = n^2/2 = O(n^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = 0;
        int tmp;
        for(int i =0;i < nums.size();i++) {
            tmp = 1;
            for(int j=i;j < nums.size();j++) {
                tmp = tmp*nums[j];
                if (tmp > maxP) {
                    maxP = tmp;
                }
            }
        }
        return maxP;
    }
};