// 這個交上去會TLE XD

class Solution {
public:
    int tribonacci(int n) {
        switch (n)
        {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 1;
            
            default:
                break;
        }
        return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};