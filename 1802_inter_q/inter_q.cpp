#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:
    略

note: 
    1. 最大值
        for same n and maxSum, the biggest ret would be k = 0 or n:
        3 4 5 6 7 25
        2 3 4 5 6 20
        1 2 3 4   10

        because nth number is the biggest, so the whole array becomes a triangle
        therefore we can obtain pmax

    2. 判斷是否正確
        左邊區域面積+右邊區域面積
        都用梯形去算，詳見底下註解

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    static int maxValue(int n, int index, int maxSum) {
        int leftCount = index;
        int rightCount = n - index - 1;
        
        auto getSum = [&](int x, int count) -> long long {
            // x 表示假設峰值為 x，計算一側的最小和
            if (x > count) {
                // 可以形成完整的等差數列：從 (x - count) 到 (x - 1)
                return (long long)(x - 1 + x - count) * count / 2;
            } else {
                // 部分等差數列，再加上剩餘的 1
                return (long long)x * (x - 1) / 2 + (count - (x - 1));
            }
        };

        int low = 1, high = maxSum;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            long long leftSum = getSum(mid, leftCount);
            long long rightSum = getSum(mid, rightCount);
            long long total = leftSum + mid + rightSum; // 加上峰值本身
            
            if (total <= maxSum) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
    

// test function
int main(){
    // call solution function
    cout << Solution::maxValue(5,19,4);

    return 0;
}