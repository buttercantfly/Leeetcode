class Solution {
public:
    int climbStairs(int n) {
        // 試試看用數學方法
        // 失敗，因為在算C的時候數字會太大
        // 可以嘗試對C做修正 讓型別能容納(輸入n<45)
        int n_2 = n/2;
        int n_1 = n%2;
        int res = 0;
        for(int i = n_1;i <= n_2 + i;i = i+2){
            res += C(n_2 + i, i);
            n_2--;
        }
        return res;
    }
    
    int C(int n, int k){
        long num = 1;
        long deno= 1;
        long nn = (long)n;
        for(int i = 0;i<k;i++){
            num *= n; // 會太大 long 也塞不下
            deno*= i+1;
            n--;
        }
        return (int)(num/deno);
    }
};