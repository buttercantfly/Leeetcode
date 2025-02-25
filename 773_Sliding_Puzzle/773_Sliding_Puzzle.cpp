#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// cord(y,x)
using cord = pair<int,int>;

// Class Solution copy here
const vector<cord> cClock = {{0,0},{0,1},{0,2},{1,2},{1,1},{1,0}};
const vector<int> validSequence = {1,2,3,5,4};
const vector<cord> direction = {{1,0},{0,-1},{-1,0},{0,1}};

class Solution {
private:
    bool isSequenceValid(vector<vector<int>>& board) {
        // find 1's index
        int x = 0,y = 0,i = 0;
        for (;y < 2;y++) {
            x = 0;
            for (;x < 3;x++) {
                if (board[y][x] == 1) break;
            }
            if (x != 3 && board[y][x] == 1) break;
        }

        for (; i < 6; i++)
        {
            if (cClock[i].first == y && cClock[i].second == x) break;
        }

        for (int step = 0; step < 5; step++)
        {
            if (board[cClock[i].first][cClock[i].second] == 0) step--;
            else if (board[cClock[i].first][cClock[i].second] != validSequence[step]) return false;
            i++;
            i = i%6;
        }
        return true;
    }

    cord findZero(vector<vector<int>>& board) {
        int y=0,x=0;
        for (;y < 2;y++) {
            for (x = 0;x < 3;x++) {
                if (board[y][x] == 0) break;
            }
            if (x != 3 && board[y][x] == 0) break;
        }
        return cord(y,x);
    }

    bool isBoardValid(vector<vector<int>>& board) {
        return board == vector<vector<int>>{{1,2,3},{4,5,0}};
    }

    bool isInBoard(cord c) {
        if (c.first < 0 || c.first > 1 || c.second < 0 || c.second > 2) return false;
        else return true;
    }

    void nextStep(queue<pair<vector<vector<int>>,int>>& boardQueue) {
        cord zeroPos = findZero(boardQueue.front().first);
        cout << zeroPos.first << " " << zeroPos.second << endl;
        for (int i = 0; i < 4; i++)
        {
            cord target = {zeroPos.first + direction[i].first, zeroPos.second + direction[i].second};
            cout << target.first << " " << target.second << endl;
            if (isInBoard(cord(target.first, target.second))) 
            {
                cout << target.first << " " << target.second << endl;
                vector<vector<int>> curBoard = boardQueue.front().first;
                swap(curBoard[zeroPos.first][zeroPos.second], curBoard[target.first][target.second]);
                if (!visitedBoards.count(boardToString(curBoard)))
                {
                    boardQueue.push(pair<vector<vector<int>>,int>(curBoard ,boardQueue.front().second+1));
                    visitedBoards.insert(boardToString(curBoard));
                }
            }
        }
    }

    string boardToString(vector<vector<int>>& board) {
        string ret = "";
        for (int y=0;y < 2;y++) {
            for (int x=0;x < 3;x++) {
                ret += board[y][x];
            }
        }
        return ret;
    }

public:
    unordered_set<string> visitedBoards;

    int slidingPuzzle(vector<vector<int>>& board) {
        // if(!isSequenceValid(board)) return -1;
        // cout << "isSequenceValid pass\n";
        
        queue<pair<vector<vector<int>>,int>> boardQueue;
        cout << "queue define pass\n";
        boardQueue.push(pair(board,0));
        visitedBoards.insert(boardToString(boardQueue.front().first));
        cout << "queue push pass\n";
        while (!isBoardValid(boardQueue.front().first))
        {
            cout << "isBoardValid pass\n";
            if (boardQueue.empty()) return -1;
            nextStep(boardQueue);
            boardQueue.pop();
        }
        
        return boardQueue.front().second;
    }
};

// test function
int main(){
    // given values
    vector<vector<int>> nums = {{1,2,3},{5,4,0}};
    int target = 0;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.slidingPuzzle(nums);

    // print out answers 
    cout << ans <<endl;

    return 0;
}