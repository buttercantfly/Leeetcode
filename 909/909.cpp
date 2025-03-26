#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
question:

note: 
    909. Snakes and Ladders
    DFS

improve:
    
*/

// Class Solution copy here
class Solution {
private:
    pair<int, int> position(int i, int n) {
        // assert(i < 1);
        // assert(i > n*n);
        pair<int, int> pr;
        pr.first  = n - ((i-1)/n + 1); // row
        if(pr.first % 2 == 1) {
            pr.second = (i-1) % n;
        } else {
            pr.second = n - i % n;
        }
            cout << i << ' ' << pr.first << ' ' << pr.second << endl;
        return pr;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // greedy? nope
        // dp? nope
        // because there might be ladders connected alone 
        // dp didnt record how the current step's path
        // if last step is reached by a ladder or snake would
        // violate the problem's description
        
        // BFS -> it can act like a climber and while traversing
        // it has a information about current steps while traversing

        // queue for bfs
        queue<int> que;
        int step = 1;
        
        // lets do true for left to right and false is the other way

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        for(int i = 1; i <= 6; i++) {
            if(i >= n*n) return step;
            // cout << i << ' ' << n << endl;
            pair<int, int> pos = position(i, n);
            // cout << pos.first << ' ' << pos.second << endl;
            if(board[pos.first][pos.second] != -1) que.push(board[pos.first][pos.second]);
            else que.push(i);
        }
        
        while(!que.empty()) {
            step++;
            for(int i = 1; i <= 6; i++) {
                if(que.front() + i > n*n) {
                    continue;
                }
                if(que.front() + i == n*n) return step;

                pair<int, int> pos = position(que.front()+i, n);

                // cout << pos.first << ' ' << pos.second << endl;
                if(visited[pos.first][pos.second]) {
                    cout << "visited\n" ;
                    continue;
                }
                
                if(board[pos.first][pos.second] != -1) que.push(board[pos.first][pos.second]);
                else que.push(que.front()+i);

                visited[pos.first][pos.second] = true;
            }
            que.pop();
        }

        return -1;
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