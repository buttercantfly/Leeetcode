#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    這個檔案是網路上找的
    他用的方法是把 diag 和 anti_diag 弄成個 col/row 的概念
    所以我們在檢查的時候只要檢查該點的 col, row, diag, anti_diag 就好了
    不需要去 traverse 整個 board

improve:
    
*/

// Class Solution copy here
class Solution {
    public:
        int totalNQueens(int n) {
        vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
        return solve(col, diag, anti_diag, 0);
    }
       
    int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
        int n = size(col), count = 0;
        if(row == n) return 1;
        for(int column = 0; column < n; column++)           
            if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){ 
                col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;
                count += solve(col, diag, anti_diag, row + 1); 
                col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false; 
            }                                
        return count;
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