#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    string 可以random access
    string s = "012345";
    s[0] -> 0
    s[1] -> 1

    vector 同理
    所以可以用 table[x][y] 的方式進行write and read

    brute force?

improve:
    
    因為用寫入的，所以速度很慢，而且memory超用很多ㄏㄏ
    => 檢查路徑有沒有queen就好了 不需要寫一個新的

*/

// Class Solution copy here
class Solution {
private:
    vector<vector<string>> ret;

    void marker(vector<string>& board, int x, int y) {
        if (board[x][y]!='Q') board[x][y] = 'v';
    }
    // 遇到Q要跳過 待改
    vector<string> markboard(int n, vector<string> board, int x, int y) {
        for (int ay = 0; ay < n; ay++) marker(board, x, ay); // 左右
        for (int ax = 0; ax < n; ax++) marker(board, ax, y); // 上下
        for (int ax = x+1, ay = y+1; ax < n  && ay < n ; ax++, ay++) marker(board, ax, ay); // 右下
        for (int ax = x-1, ay = y-1; ax > -1 && ay > -1; ax--, ay--) marker(board, ax, ay); // 左上

        for (int ax = x+1, ay = y-1; ax < n  && ay > -1; ax++, ay--) marker(board, ax, ay); // 右上
        for (int ax = x-1, ay = y+1; ax > -1 && ay < n ; ax--, ay++) marker(board, ax, ay); // 左下

        board[x][y] = 'Q';
        return board;
    }

    void backtracking(int n, int N_q, vector<string> level_board, int p_x, int p_y) {
        if (N_q == n) {
            ret.push_back(level_board);
            return;
        }
        for (int x = p_x; x < n; x++)
        {
            int y;
            if (x == p_x) y = p_y;
            if (x >  p_x) y = 0;
            for (; y < n; y++)
            {
                if (level_board[x][y] == '.')
                {
                    backtracking(n, N_q+1, markboard(n, level_board, x, y), x, y);
                }
            }
        }
        return; // if no place for queen
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> origin_board = vector<string>(n, string(n,'.'));
        backtracking(n, 0, origin_board, 0, 0);
        for (int i = 0; i < ret.size(); i++)
        {
            for (int j = 0; j < ret[i].size(); j++)
            {
                for (int k = 0; k < ret[i][j].size(); k++)
                {
                    if (ret[i][j][k] == 'v') ret[i][j][k] = '.';
                }                
            }
        }
        return ret;
    }
};

// test function
int main(){
    // given values
    int n = 4;

    // call solution function
    
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);

    // print out answers     

    return 0;
}