#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    現在問題是怎樣終止ㄏㄏ
    => 用"return"作為終止的點(因為return了也就沒有繼續執行了)
    if(callfunction()) return true;
    讓整個recursion一路return上去
improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<vector<char>> retBoard;
    bool numIsValid(vector<vector<char>>& board, int x, int y) {
        // xy方向
        for (int i = 0; i < 9; i++)
        {
            if (i != y && board[x][y] == board[x][i]) return false;
            if (i != x && board[x][y] == board[i][y]) return false;
        }
        // 方格
        int i_init   = (x/3)*3;
        int i_init_b = i_init+3;
        int j_init   = (y/3)*3;
        int j_init_b = j_init+3;
        
        // 注意init跟i本身要分開處理，因為每次i的loop j就要重新歸回j_init
        for (int i = i_init; i < i_init_b; i++)
        {
            for (int j = j_init; j < j_init_b; j++)
            {
                if ((i!=x && j!=y) && board[x][y] == board[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int n = 1; n <= 9; n++)
                    {
                        board[i][j] = n + 48;
                        if (numIsValid(board, i, j)) {
                            if(backtracking(board)) return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true; // 當兩層for都跑完就代表整個棋盤都符合board != '.' 也就表示全部空格都填完了
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
        return;
    }
};

// test function
int main(){
    // given values
    vector<vector<char>> board
    {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };


    // call solution function
    
    Solution sol;
    sol.solveSudoku(board);

    return 0;
}