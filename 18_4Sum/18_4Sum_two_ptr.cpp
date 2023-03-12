#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
note: 
    注意本題summation是等於target而非0
    因此無法先用條件跳過一些情況

    很大重點是利用"往前推"去除掉相同的情形
    但在"何時"往前推，是需要審慎考慮的

improve:
    
    (不能因為測資還是會超過ㄏㄏ)
    其實應該可以不需要用到long long，因為nums[i]+nums[j]最大值是小於int的
    所以把i_j跟l_k放到等號兩邊就沒問題了
*/

// Class Solution copy here
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        // unordered_set<int> set;
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for (int i = 0; i < size-3; i++)
        {
            for (int j = i+1; j < size-2; j++)
            {
                long long num_i_j = nums[i] + nums[j];

                // if(set.count(nums[i])) continue;

                int k = j+1;    // 從j的下個開始
                int l = size-1; // 從最後開始
                while (k < l)
                {
                    long long t = nums[k] + nums[l];
                    if(t + num_i_j == target) {
                        ret.push_back(vector<int> {nums[i],nums[j],nums[k],nums[l]});

                        while (k < l && nums[k] == nums[k+1]) k++;
                        while (k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                    else if(t + num_i_j < target) k++;
                    else l--;
                }

                // set.insert(nums[i]);

                while (j < size-2 && nums[j] == nums[j+1]) j++; 
                // k和l會跑完所有nums[i]+nums[j]的可能性 因此可以將j往前推 
                // (不需要再看同樣的數值因為往前只會讓選擇變少並造成重複的情形)
            }

            while (i < size-3 && nums[i] == nums[i+1]) i++; 
            // 同j迴圈裡，nums[i]的可能性都看過了 因此將i往前推
        }
        return ret;
    }
};


// test function
int main(){
    // given values
    // first test
    vector<int> nums = {1,0,-1,0,-2,2}; // -2 -1 0 0 1 2
    // 1. -2 -1 1 2
    // 2. -2  0 0 2
    // 3. 
    int target = 0;

    Solution s;
    vector<vector<int>> ans = s.fourSum(nums, target);
    
    cout << "Test 1:" << endl;

    for (vector<int> i: ans)
    {
        cout << "[" ;
        for (int k: i)
        {
            cout << k << ", ";
        }
        cout << "] ";
    }

    nums = {2,2,2,2,2};
    target = 8;

    ans = s.fourSum(nums, target);
    
    cout << endl;
    cout << "Test 2:" << endl;

    for (vector<int> i: ans)
    {
        cout << "[" ;
        for (int k: i)
        {
            cout << k << ", ";
        }
        cout << "] ";
    }

    cout << endl;
    cout << "End Test." << endl;

    return 0;
}