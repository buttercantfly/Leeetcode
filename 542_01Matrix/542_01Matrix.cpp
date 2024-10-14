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

improve:
    
*/

// Class Solution copy here
class Solution {
public:

    bool is_in_matrix(int i, int j, vector<vector<int>>& mat) {
        return (i < 0)||(j < 0)||(i >= mat.size())||(j >= mat[0].size());
    }

    void find_min_distance(int i, int j, 
            vector<vector<int>>& mat, vector<vector<int>>& distances) {
        for (size_t i = 0; i < ; i++)
        {
            /* code */
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> distances = mat;
        int current_min = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                find_min_distance(i,j,mat,distances);
            }
        }
        
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
