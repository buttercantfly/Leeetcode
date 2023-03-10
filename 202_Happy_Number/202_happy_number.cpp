#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
note: 
    重點: 如果不是happy number就會進入一個無限迴圈
    => 如果重複的乘積就知道不是happy number
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int tmp = n;
        
        while (!set.count(tmp))
        {
            set.insert(tmp);
            tmp = dsqrsum(tmp);
            if(tmp == 1) return true;
        }
        return false;
    }

    int dsqrsum(int n) {
        int ret = 0;
        for (int tmp = n; tmp > 0; tmp/=10)
        {
            ret += (tmp%10)*(tmp%10);
        }
        return ret;
    }
};


// test function
int main(){
    // given values
    int target = 19;
    Solution s;
    cout << s.isHappy(target) << endl;

    return 0;
}