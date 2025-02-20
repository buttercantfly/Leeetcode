#include <iostream>
#include <string>
#include <vector>
#include <deque>
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
    public:
        vector<vector<int>> visited;
    
        void dummyHelper(vector<vector<int>>& board, int curI, int curJ) {
            // 要怎麼去定義一路往上?
        }
    
        int snakesAndLadders(vector<vector<int>>& board) {
            visited = board;
            
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