#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    找到兩個島之後我就不會ㄌ

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int islands[4];
        int islandnum = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (isIsland(grid, i, j) == 0){
                    islands[islandnum] = i;
                    islands[islandnum+1] = j;
                    islandnum += 2;
                }
            }
        }
        
    }

    int isIsland(vector<vector<int>>& grid, int n, int m) {
        int ret = 0;
        if(n != 0) ret += grid[n-1][m];
        if(m != 0) ret += grid[n][m-1];
        if(n != grid.size()) ret += grid[n+1][m];
        if(m != grid[0].size()) ret += grid[n][m+1];
        return ret;
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