#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    跟找wiggle substring有異曲同工之妙
    profit從何而來?
    股票上升帶來的difference
    =>只要一直去找index當前看到的最低價，然後只要股票隔天會往下跌前賣掉即可

    1. 每天都買股票
    2. 若明天股票下跌則持有股票賣出
    3. 若明天股票上漲則持續持有，若今天是最後一天則賣出

    =>因為股票可以當天買當天買，沒有買賣限制，因此只要下跌前賣掉再抓時間買就好了

improve:
    事實上不需要這麼麻煩，同樣的思路=>每天買明天賣，只取正數其實就是最優解了
    
*/

// Class Solution copy here
class Solution {
private:
    int profit = 0;
public:
    int maxProfit(vector<int>& prices) {
        int boughtValue = -1; // 因為有股票價值是零?...所以改成-1
        for (int i = 0; i < prices.size(); i++)
        {
            if (boughtValue == -1) boughtValue = prices[i]; // 未持有股票則先買股票
            if (i+1 == prices.size() || prices[i+1] < prices[i])
            {
                profit += prices[i] - boughtValue; // 結算獲利
                boughtValue = -1; // 賣出股票
            }
            else if (prices[i+1] >= prices[i]) continue;
        }
        return profit;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";

    // call solution function
    /*
    Solution sol;
    int ans = sol.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}