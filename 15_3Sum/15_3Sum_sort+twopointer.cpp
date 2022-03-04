#include <vector>
#include <algorithm>

/*
    注意他要求不要有重複的答案(duplicate triplets)

    naive 
    => n^3

    如果使用sort + two pointer?
    => nlongn + n*(n)
    
    用two sum的解
    => 選定一個數*(用hash map看two sum的做法)
    => n*(n)
*/


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        std::vector<std::vector<int>> res;

        if(nums.size() < 3){
            return res;
        }

        std::sort(nums.begin(), nums.end()); // 用迭代 sort
        

        for(int i = 0;i< nums.size()-2;i++){
            
            int target = -nums[i];
            int r = nums.size() - 1;
            int l = i + 1;

            if(target < 0) break;

            while(l<r) {
                int sum = nums[l]+nums[r];
                
                if      (sum > target) r--;
                else if (sum < target) l++;
                else{
                    res.push_back(std::vector<int>{nums[i],nums[l],nums[r]});

                    // 把重複的k, l往前推
                    while(l<r && nums[l] == nums[l+1]) l++;
                    while(l<r && nums[r] == nums[r-1]) r--;
                    l++; r--; //大哥你漏了這一行喔 :)))) 所以你的l跟r根本沒推進 一直困在這個l跟r 智障 幹 一個小時就過了 操
                }

            }
            // 注意要用 < 不能用 != 因為可能會交錯掉導致出事
            // 少用 "!=" !!!

            // 把重複i往前推
            while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        
        return res;
    }
};


/*
    [-1,0,1,2,-1,-4]
sort:
    [-4,-1,-1,0,1,2]

*/

int main() {
    Solution sol;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    sol.threeSum(nums);
    
    return 0;
}