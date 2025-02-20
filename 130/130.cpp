#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    ******************* if we put our recursive function in an "and" declaration, we the first function return false,
     the second function will not be called. So the recursive function would not be called as we intended. *******************
     
improve:
    
*/

// Class Solution copy here
class Solution {
    public:
        // only mark as 'V' is visited else are unvisited yet
        vector<vector<char>> visited;
        
        bool isSurrounded(vector<vector<char>>& board, int i, int j) {
            // if reach outside => region is not surrounded
            if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
            
            if(visited[i][j] == 'V' || board[i][j] == 'X') return true;
            // visited
            visited[i][j] = 'V';
            // recursive 
            bool im1 = isSurrounded(board, i-1, j);
            bool ip1 = isSurrounded(board, i+1, j);
            bool jm1 = isSurrounded(board, i, j-1);
            bool jp1 = isSurrounded(board, i, j+1);
            return im1 && ip1 && jm1 && jp1;
            // return (isSurrounded(board, i-1, j) && isSurrounded(board, i+1, j) && isSurrounded(board, i, j-1) && isSurrounded(board, i, j+1));
        }
    
        void mark(vector<vector<char>>& board, int i, int j) {
            if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
            if(board[i][j] == 'X') return;
            board[i][j] = 'X';
            // recursively mark
            mark(board, i-1, j);
            mark(board, i+1, j);
            mark(board, i, j-1);
            mark(board, i, j+1);
        }
        
        void solve(vector<vector<char>>& board) {
            visited = board;
            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board[0].size(); j++) {
                    if(visited[i][j] == 'V') continue;
                    if(board[i][j] == 'X') continue;
                    if(isSurrounded(board, i, j)) mark(board, i, j);
                }
            }
            return;
        }
    };

// test function
int main(){
    // given values
    vector<vector<char>> board = {
        {'O','O','O','O','X','X'},
        {'O','O','O','O','O','O'},
        {'O','X','O','X','O','O'},
        {'O','X','O','O','X','O'},
        {'O','X','O','X','O','O'},
        {'O','X','O','O','O','O'}};

/*
[
["O","O","O","O","X","X"],
["O","O","O","O","O","O"],
["O","X","O","X","O","O"],
["O","X","O","O","X","O"],
["O","X","O","X","O","O"],
["O","X","O","O","O","O"]]
*/

    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    sol.solve(board);

    // print out answers

    return 0;
}