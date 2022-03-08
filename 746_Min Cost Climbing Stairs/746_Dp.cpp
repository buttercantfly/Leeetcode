class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0 || n == 1) return 0;
        if(n == 2) return std::min(cost.at(0), cost.at(1));

        std::vector<int> dp;
        dp.reserve(n+1);
        dp.push_back(0);
        dp.push_back(0);

        int i = 2;
        while(i < n+1){
            dp.push_back(std::min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]));
            i++;
        }
        return dp.back();
    }
};