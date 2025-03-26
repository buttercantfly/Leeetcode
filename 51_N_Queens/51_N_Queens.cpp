#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    this method is create a new board to avoid code complexity
    
improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int ret = 0;
    void backtracking(vector<vector<int>>& board, int row, int n){
        if(row == n){
            ret++;
            return;
        }
        // traverse through the row
        for(int i = 0; i < n; i++){
            if(board[row][i] == 0){
                // create a new_board for backtracking (so we dont change the original board)
                vector<vector<int>> new_board = board;
                // mark the new board with the new queen
                // new_board[row][i] = 1; actaully we dont need to mark this
                // and dont even need to mark the row because we are going to the next row
                // mark the column and diagonals
                for(int x = 1; row+x < n; x++){
                    new_board[row+x][i] = 1;
                    if(i-x >= 0) new_board[row+x][i-x] = 1;
                    if(i+x <  n) new_board[row+x][i+x] = 1;
                }

                backtracking(new_board, row+1, n);
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        // only have to consider the first
        // and we actually just have to consider the first half
        // because the second half is just the mirror of the first half
        backtracking(board, 0, n);
        
        return ret;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 4;
    string s = "";

    // call solution function
    Solution sol;
    int ans = sol.totalNQueens(target);

    // print out answers 
    cout << ans;

    return 0;
}