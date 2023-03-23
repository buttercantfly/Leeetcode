#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:
    You are given an array of integers nums, 
    there is a sliding window of size k 
    which is moving from the very left of the array to the very right. 
    You can only see the k numbers in the window. 
    Each time the sliding window moves right by one position.

    Return the max sliding window.

note: 
    windwo size = k
    nums length = n

    naive approach: O(k*n)
    => max(m elements)

    Monotonic Queue! 單調隊列
    => monotonically decreasing queue
    重要特性: 只在乎最大值(先進入queue並小於後進者會被pop掉)，並且以FIFO方式新增元素
    => 但刪除的話因為要使隊列中沒有不需要的小值(小於新加入的元素)，所以要從後方開始檢查
    
    儲存時會長這樣
    [max|other elements]
    1. insert(x)
        while(x > back()) pop_back(); // 一路從小檢查到大
        push(x);
    2. pop() window moving
        我們只需要檢查max，因為小於max且在max左側的值都已經被丟了
        if(top() == i) pop();

improve:
    這題有點被中國人誤導= =，做題終究不要局限於題目，要根據需求去改變
    deque好用阿

    => 根據題目需求去構思一個資料結構
    => 再根據語言既有的資料結構去建立一個符合此要求的資料結構
    如本題 monotonic queue 就是以既有的 deque 去操作

*/

// Class Solution copy here
class Solution {
public:
    deque<int> mQueue;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        
        for (int i = 0; i < k; i++) push(nums, i);
        ret.push_back(nums[mQueue.front()]);

        for (int i = 0; i < nums.size()-k; i++)
        {
            pop(nums, i);
            push(nums, k+i);
            ret.push_back(nums[mQueue.front()]);
        }
        
        return ret;
    }

    void push(const vector<int>& nums, int x) {
        while (!mQueue.empty() && nums[x] > nums[mQueue.back()])
        {
            mQueue.pop_back();
        }
        mQueue.push_back(x);
    }

    void pop(const vector<int>& nums, int i) {
        if (nums[mQueue.front()] == nums[i]) mQueue.pop_front();
        else;
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;

    // call solution function
    
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, k);

    // print out answers 
    cout << "{ ";
    for (int i:ans)
    {
        cout << i << ", ";
    }
    cout << "}";
    return 0;
}