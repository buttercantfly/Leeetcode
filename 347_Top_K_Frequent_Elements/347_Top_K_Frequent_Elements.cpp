#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
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

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i: nums)
        {
            if (map.count(i)) map[i] += 1;
            else map[i] = 1;
        }
        
        for (pair<int, int> p: map)
        {
            int c = p.second;
        }
        
    }
};

class six_minheap {
private:
    int heap[6] = {INT_MAX};
public:
    void extractMin_and_insertKey(int k) {
        heap[0];
    }

    int getMin() {
        return heap[0];
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