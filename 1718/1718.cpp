#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool helper(vector<bool>& usedNum, vector<int>& ret, int curPos, int cnt) {
        if(cnt == 0) return true;
        for (int i = usedNum.size()-1; i >= 0; i--)
        {
            int k = curPos;
            if(usedNum[i]) continue;
            else if(i == 0) {
                ret[curPos] = 1;
                usedNum[i]  = true;
                if(cnt-1 == 0) return true;
                while (ret[k] != 0) k++;
                if(helper(usedNum, ret, k, cnt-1)) return true;
                ret[curPos] = 0;
                usedNum[i] = false;
            }
            else if(curPos+i+1 < ret.size() && ret[curPos+i+1] == 0){
                ret[curPos] = i+1;
                ret[curPos+i+1] = i+1;
                usedNum[i] = true;
                if(cnt-2 == 0) return true;
                while (ret[k] != 0) k++;
                if(helper(usedNum, ret, k, cnt-2)) return true;
                ret[curPos] = 0;
                ret[curPos+i+1] = 0;
                usedNum[i] = false;
            }
            else continue;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {

        vector<int>  retVec(2*n-1, 0);
        vector<bool> usedNum(n, false);

        // choose the current max
        // if non success return false

        // try fill in
        // if return true set
        
        // how to identify if a number is used when travering


        // max heap -> unused nums
        // map -> pointing to positions

        helper(usedNum, retVec, 0, 2*n-1);

        return retVec;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    vector<int> ans = sol.constructDistancedSequence(5);

    // print out answers 
    for(int i: ans) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}