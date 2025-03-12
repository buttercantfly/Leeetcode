#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <cassert>
#include <algorithm>
using namespace std;

/*
question:

note: 
    why bfs?
    because it can avoid infinite loop comparing to dfs
    and it can act like a climber and while traversing
    {{-1,-1,-1,9,-1,-1},
    {-1,-1,10,7,-1,-1},
    {-1,-1,-1,-1,-1,20},
    {-1,14,-1,-1,15,20},
    {31,29,-1,-1,7,36},
    {-1,-1,-1,13,18,5}}

    這題其實麻煩在 position function 寫的超躁的
    
improve:
    
*/

// Class Solution copy here
class Solution {
private:
// position helper function
    pair<int, int> position(int i, int n) {
        assert(i >= 1);
        assert(i <= n*n);
        pair<int, int> pr;
        pr.first  = n - ((i-1)/n + 1); // row
        if(n%2 == 1) {
            if((n - ((i-1) / n)) % 2 == 0) {
                if(i % n == 0) pr.second = 0;
                else pr.second = n - i % n;
            } else {
                pr.second = (i-1) % n;
            }
        } else {
            if((n - ((i-1) / n)) % 2 == 0) {
                pr.second = (i-1) % n;
            } else {
                if(i % n == 0) pr.second = 0;
                else pr.second = n - i % n;
            }
        }
        return pr;
    }

public:
    vector<vector<int>> visited;
    queue<pair<int, int>> que;
    int minStep = INT_MAX;

    void testPosition(int n) {
        for(int i = 1; i <= n*n; i++) {
            pair<int, int> pr = position(i, n);
            cout << i << ' ' << pr.first << ' ' << pr.second << endl;
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> isVisited(n*n + 1, false);

        for(int i = 1; i <= 9; i++) {
            pair<int, int> pr = position(i, 3);
        }

        que.push({1, 0});
        isVisited[1] = true;

        while (!que.empty())
        {
            int x = que.front().first;
            int step = que.front().second;
            que.pop();

            for(int i = 1; i <= 6; i++) {
                if(x + i > n*n) break;

                int cx = position(x + i, n).first;
                int cy = position(x + i, n).second;
                
                int lors = board[cx][cy];
                
                if(lors != -1) {
                    if(isVisited[lors]) continue;
                    if(lors == n*n) {
                        if(step + 1 < minStep) minStep = step + 1;
                    }
                    que.push({lors, step + 1});
                    isVisited[lors] = true;
                } 
                else if (!isVisited[x + i]){
                    if(x + i == n*n) {
                        if(step + 1 < minStep) minStep = step + 1;
                    }
                    que.push({x + i, step + 1});
                    isVisited[x + i] = true;
                }
                else continue;
            }
        }
        
        if(minStep != INT_MAX) return minStep;
        else return -1;
    }
};

// test function
int main(){
    // given values
    vector<vector<int>> board = {{-1,-1,19,10,-1},
                                {2,-1,-1,6,-1},
                                {-1,17,-1,19,-1},
                                {25,-1,20,-1,-1},
                                {-1,-1,-1,-1,15}};

    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.snakesAndLadders(board);

    sol.testPosition(5);

    // print out answers 
    cout << ans << endl;

    return 0;
}