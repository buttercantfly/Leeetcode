#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    
improve:
    其實跟 dp 無關啦
    push 進 que 的時候就可以把上一步的資訊也丟進去
    但我們還是需要 dp 去紀錄是否有走過
*/

// Class Solution copy here
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // firstly we trnasform the board into a one-dimentional array
        vector<int> oneD_board;
        for(int i = board.size()-1; i >= 0; i--){
            int j, limit, increment;
            if((board.size() - i) % 2 == 0) 
            {
                for(j = board[i].size()-1; j >= 0 ; j--) {
                    oneD_board.push_back(board[i][j]);
                }
            }
            else
            {
                for(j = 0; j < board[i].size(); j++) {
                    oneD_board.push_back(board[i][j]);
                }
            }
        }

        // for(int i: oneD_board) cout << i << ' ';
        // cout << endl;
        // cout << oneD_board.size() << endl;

        vector<int> dp(oneD_board.size(), -1);
        dp[0] = 0;
        deque<int> que;
        que.push_back(0);

        // we should use queue to process this instead
        while (!que.empty())
        {
            /* code */
            int i = que.front();
            if(dp[i] == -1) continue;
            // each steps
            for(int j = 1; j <= 6; j++) {
                // cout << i+j << endl;
                if(i+j >= oneD_board.size()) break;

                if(oneD_board[i+j] == -1) {
                    if(dp[i+j] == -1) {
                        dp[i+j] = dp[i]+1;
                        que.push_back(i+j);
                    }
                    else dp[i+j] = min(dp[i]+1, dp[i+j]);
                }
                else {
                    if(dp[oneD_board[i+j]-1] == -1) {
                        dp[oneD_board[i+j]-1] = dp[i]+1;
                        que.push_back(oneD_board[i+j]-1);
                    }
                    else dp[oneD_board[i+j]-1] = min(dp[i]+1, dp[oneD_board[i+j]-1]);
                }

                if(i+j == oneD_board.size()-1 && dp[i+j] != INT_MAX) return dp[i+j];
            }
            que.pop_front();
        }

        return dp[oneD_board.size() - 1];
    }
};

// test function
int main(){
    // given values
    vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.snakesAndLadders(board);

    // print out answers 
    cout << ans;
    

    return 0;
}