class Solution {
public:
    int climbStairs(int n) {
        // DP
        // 想法1: 每多加入一個長度則有規則的增加方法數?
        // => 規律 n = n-1 + n-2?
        if(n == 2) return 2;
        if(n == 1) return 1;
        
        int n_2 = 1;
        int n_1 = 2;
        int f;
        for(int i = 2; i < n;i++){
            f = n_2 + n_1;
            n_2 = n_1;
            n_1 = f;
        }
        return f;
    }
};