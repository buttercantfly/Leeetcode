#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    dp
    distances for distances
    curent_min
    traversal way
    when to stop? 

    (i-1, j-1) (i-1, j) (i-1, j+1)
    (i, , j-1) (i,j)    (i,   j+1)
    (i+1, j-1) (i+1, j) (i+1, j+1)

    1 1 1
    1 0 1
    1 1 1

improve:
    用BFS反而比較快?
    -> back track
        一路return 回中心?

*/

// Class Solution copy here
class Solution {
public:
    void search_nearby(int i, int j, vector<vector<int>>& distances, bool& changed) {
        // if(distances[i][j] != INT_MAX - 10) return;
        int origin = distances[i][j];

        if(i-1 >= 0)                  distances[i][j] = min(distances[i][j], distances[i-1][j]+1);
        if(i+1 < distances.size())    distances[i][j] = min(distances[i][j], distances[i+1][j]+1);
        if(j-1 >= 0)                  distances[i][j] = min(distances[i][j], distances[i][j-1]+1);
        if(j+1 < distances[0].size()) distances[i][j] = min(distances[i][j], distances[i][j+1]+1);

        if(distances[i][j] != origin) changed = true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> distances = mat;

        for (int i = 0; i < distances.size(); i++)
        {
            for (int j = 0; j < distances[0].size(); j++)
            {
                if (distances[i][j] == 1) distances[i][j] = INT_MAX - 10;
            }
        }

        bool changed;
        while (true)
        {
            changed = false;
            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat[0].size(); j++)
                {
                    search_nearby(i,j,distances,changed);
                }
            }
            if(!changed) break;
        }

        return distances;
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
