class Solution {
public:
    // 時間不快 因為有更換儲存空間的操作(直接用dp[]會比較快)
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int n_2 = 0;
        int n_1 = 1;
        int f;
        for(int i = 2; i <= n;i++){
            f = n_2 + n_1;
            n_2 = n_1;
            n_1 = f;
        }
        return f;
    }
};