#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here

// 找正解的 LIS LDS 至少要nlogn
// 這題沒linear解
// 第一個是N^2
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        // Compute LIS up to each index
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Compute LDS from each index
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;

        // Find the maximum mountain length
        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {  // Valid peak
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }

        return n - maxMountainLength;
    }
};

// NlogN解
class Solution {
public:

    vector<int> lisLength(vector<int>& v){
        vector<int> lis = {v[0]};
        vector<int> lisLen(v.size(), 1);

        for(int i = 1 ; i < v.size() ; i++){
            if(v[i] > lis.back()){
                lis.push_back(v[i]);
            } else {
                int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
                lis[index] = v[i];
            }
            lisLen[i] = lis.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis = lisLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds = lisLength(nums);
        reverse(lds.begin(), lds.end());

        int removals = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(lis[i] > 1 && lds[i] > 1){
                removals = min(removals, n + 1 - lis[i] - lds[i]);
            }
        }

        return removals;
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {1,16,84,9,29,71,86,79,72,12};

    // call solution function
    
    Solution sol;
    int ans = sol.minimumMountainRemovals(nums);

    // print out answers 
    cout << ans;
    

    return 0;
}