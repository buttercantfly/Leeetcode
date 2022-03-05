#include <vector>
#include <stack>

/*
    1. Min Heap?
    找最小的這個想法不太行，因為sort需要NlogN

    2. "Range"
    每個數都會有一個Range 找到range就知道他佔多少了
    => 左邊的長度+1 * 右邊長度+1 (自己圖畫畫看想一下)
    => 想辦法找出每個index的"左邊長度"還有"右邊長度"

    3. 使用 Increasing Stack 個別看左邊右邊 (兩個for迴圈)
    key:以左邊長度來看如果index=i+1的數之值比index=i的數小，則他的"左邊長度"會包含所有index=i的"左邊長度"(i+1 < i)

    參考解答：
    https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/JavaC%2B%2BPython-Stack-Solution

*/


class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        
        long res = 0;
        int n = arr.size();
        std::vector<int> left(n), right(n);
        std::stack<std::pair<int,int>> s1, s2; // stack儲存pair 其中first儲存value second儲存length
        

        for(int l = 0;l < n;++l){
            int length = 1; // 自己就算長度1(至少)
            while(!s1.empty() && s1.top().first > arr[l]){
                length += s1.top().second;
                s1.pop();
            }
            s1.push({arr[l], length});
            left[l] = length;
        }

        for(int r = n-1;r >= 0;--r){
            int length = 1; // 自己就算長度1(至少)
            while(!s2.empty() && s2.top().first >= arr[r]){
                length += s2.top().second;
                s2.pop();
            }
            s2.push({arr[r], length});
            right[r] = length;
        }

        for(int i = 0;i < n;++i){
            res = (res + (long)arr[i] * left[i] * right[i]) % (long)(1e9+7); //這行是用來mod
        }

        return res;
    }
};
