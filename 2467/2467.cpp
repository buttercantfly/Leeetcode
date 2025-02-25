#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
question:

note: 
    1. alice's dfs
        - end: leaf node -> no next node
        - 

    2. bob's dfs


    3. dfs together
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    void helper(int curA, int curB) {
        // when helper is called, curA and curB both have already visited

        // return if curA reach leaf
        if(!edges.count(curA) || edges[curA].empty()) {
            if(aProfit > maxAProfit) maxAProfit = aProfit;
            return;
        }

        int aTmp, bTmp;
        for(int i: edges[curA]) {
            aTmp = amount[i];
            aProfit += aTmp;
            amount[i] = 0;

            // if curB reach 0, just ignore curB
            if(curB != 0) {
                for(int j: edges[curB]) {
                    bTmp = amount[j];
                    amount[j] = 0;
                    helper(i, j);
                    if(i == j) amount[j] = aTmp;
                    else amount[j] = bTmp;
                }
            } else {
                helper(i, curB);
            }

            amount[i] = aTmp;
            aProfit -= amount[i];
        }
    }
    vector<int> amount;
    unordered_map<int, vector<int>> edges;
    int aProfit = 0;
    int maxAProfit = INT_MIN;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {  
        // initialization
        for (vector<int> pr: edges)
        {
            this->edges[pr[0]].push_back(pr[1]);
        }
        
        this->amount = amount;
        
        // check if alice already in ending point
        if(!this->edges.count(0) || this->edges[0].empty()) {
            return amount[0];
        }

        // first step
        aProfit = this->amount[0];
        this->amount[0] = 0;
        this->amount[bob] = 0;
        
        // start recursion
        helper(0, bob);

        return maxAProfit;
    }
};

// test function
int main(){
    // given values
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    vector<int> amount = {-2,4,2,-4,6};
    int bob = 3;

    // call solution function
    
    Solution sol;
    int ans = sol.mostProfitablePath(edges, bob, amount);

    // print out answers 
    cout << ans;
    

    return 0;
}