#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

/*
question:
    Given an integer array nums and an integer k, return the k most frequent elements. 
    You may return the answer in any order.

note: 
    1. unodered_map: key為 num 每次丟進去 value += 1
    => O(n)

    2. min_heap
    => 維持只有六個elements

    how to implement?
    => 於c++內請使用priority_queue

    priority_queue<int>
    priority_queue<int, vector<int>, greater<int>>
    priority_queue<T, vector<T>, cmp<T>>
    
    <T> and cmp example:
    => 建一個新的cmp並用operator overload
    => 回傳bool值　true則b比a優先

    => 範例：偶數的優先權比奇數的大、且數字越小優先權越大
    template <typename T>
    class cmp {
        public: 
            bool operator()(T a, T b) {
                if (a % 2 == 1 && b % 2 == 0) {
                    return true;
                }
                else if (a % 2 == 0 && b % 2 ==1) {
                    return false;
                }
                else {
                    return a > b;
                }
            }
    };

improve:

    多熟悉c++內建的stl以及iterator用法

*/

// Class Solution copy here
class Solution {
public:
    // 自定義 comparison operator()
    // 注意基本上名稱是用左右node的想法 (lhs vs rhs)
    // 本題應該是要比較second(出現頻率)，並且低的較高順位 => 左大回傳true 左小回傳false
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> pque;
        vector<int> ret;

        // hash map 紀錄各數字出現次數
        for (int i: nums)
        {
            if (map.count(i)) map[i] += 1;
            else map[i] = 1;
        }
        
        // 統計完後將所有元素push進pque，並確保其維持<k的大小
        for (pair<int, int> p: map)
        {
            pque.push(p); 
            if (pque.size() > k) pque.pop();
        }
        
        while (!pque.empty())
        {
            ret.push_back(pque.top().first);
            pque.pop();
        }
        
        return ret;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    // call solution function
    
    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);

    // print out answers 
    cout << "{";
    for (int i: ans)
    {
        cout << i << ", ";
    }
    cout << "}";

    return 0;
}