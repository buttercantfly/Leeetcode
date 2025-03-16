#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    how to deal with the circular array is an issue
    
    apart from global max and current max
    we need to record current max's head
    if in second traversal, we reach the head again, we need to stop
    and if we need to abandon the current max, we need to stop too

    nononononon need to that complicated
    we just have to check the circular conditon (subarray that contains the tail and head)
    so just do 

    NONONNONOOOONONONONONONONONONOON

    this question is actaully looking for minimum subarray
    = =

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum=0, currMax=0, currMin=0;
        int mxsum_subary=INT_MIN, minsum_subary=INT_MAX;   
        for(auto i:A)
        {
            total_sum += i;
            currMax += i;
            currMin += i;

            mxsum_subary =max(mxsum_subary,  currMax);
            if(currMax < 0) currMax = 0;
            minsum_subary=min(minsum_subary, currMin);
            if(currMin > 0) currMin = 0;
        }
        return (total_sum == minsum_subary) ?mxsum_subary : max(mxsum_subary, total_sum-minsum_subary);
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {5,-3,5};
    int target = 0;
    string s = "";

    // call solution function
    Solution sol;
    int ans = sol.maxSubarraySumCircular(nums);

    // print out answers 
    cout << ans;

    return 0;
}