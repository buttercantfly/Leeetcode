#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
note: 
    dp?
    用sum作為key, count作為values
    注意本題只需要回傳"有幾個"，所以不用存index
    => 最佳為 O(n^2)
    看解答
    => 暴力解: O(n^4)
    => 加入2sum的hash想法 => O(n^3)建立hashmap + O(1)*n 可解
    => 如果建立兩個hashmap? => 2*O(n^2) + O(1)*O(n) = O(n^2)

    -----------------------------------
    Summation的hash就是利用 a+b = target
    
    
improve:
    不需要建兩個map，

*/

// Class Solution copy here
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum_map1;
        unordered_map<int, int> sum_map2;
        int ret = 0;

        for(int i: nums1){
            for(int j:nums2){

                sum_map1[i+j]++;
            }
        }

        for(int k: nums3){
            for(int l:nums4){
                sum_map2[k+l]++;
            }
        }
        
        for (unordered_map<int, int>::iterator it = sum_map1.begin(); it != sum_map1.end(); it++)
        {
            if(sum_map2.count(-(it->first))){
                ret += it->second * sum_map2[-(it->first)];
            }
        }
        
        return ret;
    }
};


// test function
int main(){
    // given values
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    // call solution function
    
    Solution s;
    int ans = s.fourSumCount(nums1,nums2,nums3,nums4);

    // print out answers 
    cout << ans;
    

    return 0;
}